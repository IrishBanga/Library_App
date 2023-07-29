/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
Version 2.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/14  Preliminary release
2023/07/29  v2.0 - added getPub() function
            Modified LibApp() constructor
            Modified run(), load(), save(), returnPub(),
            newPublication(), removePublication() and
            checkoutPub() functions
            Modified search() function to search library
            items based on value of searchFlag
            0 - search all publications (Default)
            1 - search on loan publications
            2 - search available publications
            Added deleteDMA() function to deallocate memory
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#include <iostream>
#include <fstream>
#include "LibApp.h"
#include "Utils.h"
#include "Book.h"
using namespace std;
namespace sdds
{
    LibApp::LibApp(const char* filename)
    {
        m_changed = false;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        m_publicationMenu << "Book" << "Publication";
        if (filename)
        {
            strCpy(m_filename, filename);
            load();
        }
    }

    LibApp::~LibApp()
    {
    }

    bool LibApp::confirm(const char* message)
    {
        Menu temp(message);
        temp << "Yes";
        bool res = false;
        res = temp.run();
        return res;
    }

    void LibApp::load()
    {
        cout << "Loading Data" << endl;
        ifstream fin(m_filename);
        char ch = 'x';
        NOLP = 0;
        for (int i = 0; fin; i++)
        {
            fin >> ch;
            fin.ignore();
            if (fin)
            {
                if (ch == 'P')
                {
                    PPA[i] = new Publication;
                }
                else if (ch == 'B')
                {
                    PPA[i] = new Book;
                }
                if (PPA[i])
                {
                    fin >> *PPA[i];
                    LLRN = PPA[i]->getRef();
                    NOLP = i + 1;
                }
            }
        }
    }
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
        ofstream fout(m_filename);
        for (int i = 0; i < NOLP; i++)
        {
            if (PPA[i]->getRef() != 0)
            {
                fout << *PPA[i];
                fout << endl;
            }
        }
    }

    int LibApp::search(int searchFlag)
    {
        int res = -1;
        PublicationSelector search("Select one of the following found matches:");
        int pubChoice = m_publicationMenu.run();
        if (pubChoice)
        {
            char titleTemp[256 + 1]{ "" };
            cout << "Publication Title: ";
            cin.getline(titleTemp, 256 + 1);
            for (int i = 0; i < NOLP; i++)
            {
                if (PPA[i]->getRef() != 0)
                {
                    bool check = true;
                    if (searchFlag == 1 && !PPA[i]->onLoan())
                    {
                        check = false;
                    }
                    else if (searchFlag == 2 && PPA[i]->onLoan())
                    {
                        check = false;
                    }
                    if (check && strStr(*PPA[i], ((titleTemp[0] != '\0') ? titleTemp : *PPA[i])))
                    {
                        check = true;
                        if (pubChoice == 1 && PPA[i]->type() != 'B')
                        {
                            check = false;
                        }
                        else if (pubChoice == 2 && PPA[i]->type() != 'P')
                        {
                            check = false;
                        }
                        if (check)
                        {
                            search << PPA[i];
                        }
                    }
                }
            }
            if (search)
            {
                search.sort();
                res = search.run();
                if (res <= 0)
                {
                    res = -1;
                    cout << "Aborted!" << endl;
                }
            }
            else
            {
                cout << "No matches found!";
            }
        }
        else
        {
            cout << "Aborted!" << endl;
        }
        return res;
    }

    void LibApp::returnPub()
    {
        cout << "Return publication to the library" << endl;
        int choice = search(1);
        if (choice >= 0)
        {
            cout << *getPub(choice);
            cout << endl;
            m_changed = confirm("Return Publication?");
            if (m_changed)
            {
                Date today;
                if ((today - getPub(choice)->checkoutDate()) > 15)
                {
                    cout << "Please pay $";
                    double penalty = 0.50 * ((today - getPub(choice)->checkoutDate()) - 15);
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << penalty;
                    cout.unsetf(ios::fixed);
                    cout << " penalty for being " << ((today - getPub(choice)->checkoutDate()) - 15) << " days late!" << endl;
                }
                getPub(choice)->set(0);
                cout << "Publication returned" << endl;
            }
        }
    }

    void LibApp::footer()
    {
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

    Publication* LibApp::getPub(int libRef)
    {
        int index = 0;
        bool done = false;
        for (int i = 0; i < NOLP && !done; i++)
        {
            if (PPA[i]->getRef() == libRef)
            {
                done = true;
                index = i;
            }
        }
        return PPA[index];
    }

    void LibApp::deleteDMA()
    {
        for (int i = 0; i < NOLP; i++)
        {
            delete PPA[i];
            PPA[i] = nullptr;
        }
    }

    void LibApp::newPublication()
    {
        if (NOLP == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl;
        }
        else
        {
            cout << "Adding new publication to the library" << endl;
            int choice = m_publicationMenu.run();
            Publication* temp{};
            if (choice)
            {
                if (choice == 1)
                {
                    temp = new Book;
                    cin >> *temp;
                }
                else if (choice == 2)
                {
                    temp = new Publication;
                    cin >> *temp;
                }
                if (!cin.fail())
                {
                    choice = confirm("Add this publication to the library?");
                    if (choice)
                    {
                        if (temp)
                        {
                            temp->setRef(++LLRN);
                            PPA[NOLP++] = temp;
                            m_changed = true;
                            cout << "Publication added" << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!" << endl;
                            delete temp;
                            temp = nullptr;
                        }
                    }
                    else
                    {
                        cout << "Aborted!" << endl;
                    }
                }
                else
                {
                    cout << "Aborted!" << endl;
                }
            }
            else
            {
                cout << "Aborted!" << endl;
            }
        }
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from the library" << endl;
        int choice = search();
        if (choice >= 0)
        {
            cout << *getPub(choice);
            cout << endl;
            m_changed = confirm("Remove this publication from the library?");
            if (m_changed)
            {
                getPub(choice)->setRef(0);
                cout << "Publication removed" << endl;
            }
        }
    }

    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library" << endl;
        int choice = search(2);
        if (choice >= 0)
        {
            cout << *getPub(choice);
            cout << endl;
            m_changed = confirm("Check out publication?");
            if (m_changed)
            {
                int temp = 0;
                bool done = false;
                cout << "Enter Membership number: ";
                do
                {
                    temp = getInt();
                    if (temp >= 9999 && temp <= 99999)
                    {
                        done = true;
                    }
                    else
                    {
                        cout << "Invalid membership number, try again: ";
                    }
                } while (!done);
                getPub(choice)->set(temp);
                cout << "Publication checked out";
            }
        }
        cout << endl;
    }

    void LibApp::run()
    {
        bool done = false;
        do
        {
            int choice = m_mainMenu.run();
            if (choice == 0)
            {
                if (m_changed)
                {
                    choice = m_exitMenu.run();
                    if (choice == 0)
                    {
                        choice = confirm("This will discard all the changes are you sure?");
                        if (choice == 1)
                        {
                            done = true;
                        }
                    }
                    else if (choice == 1)
                    {
                        save();
                        done = true;
                    }
                }
                else
                {
                    done = true;
                }
                deleteDMA();
            }
            else if (choice == 1)
            {
                newPublication();
            }
            else if (choice == 2)
            {
                removePublication();
            }
            else if (choice == 3)
            {
                checkOutPub();
            }
            else if (choice == 4)
            {
                returnPub();
            }
            cout << endl;
        } while (!done);
        footer();
    }
}
