/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/08  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Menu.h"
#include "Utils.h"
namespace sdds 
{
    MenuItem::MenuItem(const char* newName)
    {
        if (newName != nullptr)
        {
            Name = new char[strLen(newName)+1];
            strCpy(Name, newName);
        }
    }
    
    MenuItem::operator bool() const
    {
        return(Name!=nullptr);
    }

    MenuItem::operator const char*() const
    {
        return Name;
    }

    ostream& MenuItem::display()const
    {
        if (Name != nullptr)
        {
            cout << Name;
        }
        return cout;
    }

    MenuItem::~MenuItem()
    {
        if (Name != nullptr)
        {
            delete[] Name;
            Name = nullptr;
        }
    }
    
    Menu::Menu(const char* newTitle)
    {
        if (newTitle != nullptr)
        {
            title.Name = new char[strLen(newTitle)+1];
            strCpy(title.Name, newTitle);
        }
        else
        {
            title.Name = nullptr;
        }
    }

    Menu::~Menu()
    {
        for (int i = 0; i < noOfItems; i++)
        {
            delete items[i];
        }
    } 

    ostream& Menu::display()const
    {
        if (title != nullptr)
        {
            title.display();
        }
        return cout;
    }

    ostream& Menu::displayMenu()const
    {
        if (title != nullptr)
        {
            display();
            cout << ":" << endl;
        }
        for (int i = 0; i < noOfItems; i++)
        {
            cout.width(2);
            cout << i + 1<<"- ";
            items[i]->display();
            cout << endl;
        }
        cout << " 0- Exit" << endl<<"> ";
        return cout;
    }

    unsigned int Menu::run()
    {
        displayMenu();
        unsigned int ret=getMMInt(0,noOfItems,"Invalid Selection, try again: ");
        return ret;
    }

    unsigned int Menu::operator~()
    {
        return run();
    }

    Menu& Menu::operator<<(const char* menuitemConent)
    {
        if (noOfItems < MAX_MENU_ITEMS && menuitemConent != nullptr)
        {
            items[noOfItems] = new MenuItem;
            items[noOfItems]->Name = new char[strLen(menuitemConent) + 1];
            strCpy(items[noOfItems]->Name, menuitemConent);
            noOfItems++;
        }
        return *this;
    }

    ostream& operator<<(ostream& os, const Menu& menu)
    {
        menu.display();
        return os;
    }

    Menu::operator int()const
    {
        return noOfItems;
    }
    
    Menu::operator unsigned int()const
    {
       return (unsigned int)noOfItems;
    }
    
    Menu::operator bool()const
    {
        return (noOfItems > 0);
    }

    const char* Menu::operator[](unsigned int item)const
    {
        int toPrint = item % (noOfItems);
        return (const char*)items[toPrint]->Name;
    }
}
