/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{
    const int MAX_MENU_ITEMS = 20;
    class Menu;

    class MenuItem
    {
        char* Name{ nullptr };
        MenuItem() = default;
        MenuItem(const char* newName);
        MenuItem(MenuItem& intonewItem) = delete;
        MenuItem& operator=(MenuItem& existingItem) = delete;
        operator bool() const;
        operator const char* () const;
        std::ostream& display()const;
        ~MenuItem();
        friend class Menu;
    };

    class Menu
    {
        MenuItem title{};
        MenuItem* items[MAX_MENU_ITEMS]{ nullptr };
        int noOfItems{};
    public:
        Menu() = default;
        Menu(const char* newTitle);
        Menu(Menu& intonewItem) = delete;
        ~Menu();
        Menu& operator=(Menu& existingItem) = delete;
        std::ostream& display()const;
        std::ostream& displayMenu()const;
        unsigned int run();
        unsigned int operator~();
        Menu& operator<<(const char* menuitemConent);
        operator int()const;
        operator unsigned int()const;
        operator bool()const;
        const char* operator[](unsigned int itemNo)const;
    };
    std::ostream& operator<<(std::ostream& os, const Menu& menu);
}
#endif // !SDDS_MENU_H
