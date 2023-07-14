/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/14  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#include <iostream>
#include "LibApp.h"
using namespace std;
namespace sdds 
{    
    LibApp::LibApp()
    {
        m_changed = false;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
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
    }
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
    }

    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    void LibApp::footer()
    {
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
    
    void LibApp::newPublication()
    {
        cout<< "Adding new publication to library" <<endl;
        m_changed = confirm("Add this publication to library?");
        if (m_changed)
        {
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        m_changed = confirm("Remove this publication from the library?");
        if (m_changed)
        {
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub()
    {
        search();
        m_changed = confirm("Check out publication?");
        if (m_changed)
        {
            cout << "Publication checked out" << endl;
        }
    }

    void LibApp::run()
    {
        int choice;
        bool done = false;
        do
        {
            choice = m_mainMenu.run();
            if (choice == 0)
            {
                if (m_changed)
                {
                    choice=m_exitMenu.run();
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
