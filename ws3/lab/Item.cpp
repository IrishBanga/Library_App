/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
    /*
    setName()- sets the item name to the parameter passed(if not NULL) upto 20 characters only
    */
    void Item::setName(const char* name)
    {
        if (name != NULL)
        {
            strnCpy(m_itemName, name, 20);
        }
    }

    /*
    setEmpty()- sets the Item to a recognizable safe Empty State.
    */
    void Item::setEmpty()
    {
        m_itemName[0] = '\0';
        m_price = -1;
    }

    /*
    set()- sets an Item's data members to the arguments passed
    */
    void Item::set(const char* name, double price, bool taxed)
    {
        setName(name);
        m_price = price;
        m_taxed = taxed;
    }

    /*
    display()- displays item information in a specific format
    */
    void Item::display() const
    {
        if (isValid())  //checking if the item is valid
        {
            cout << "| ";
            cout.fill('.');
            cout.width(20);
            cout.setf(ios::left);  //aligning the item name to left
            cout << m_itemName<<" | ";
            cout.fill(' ');
            cout.setf(ios::fixed);  //displaying item price in fixed width
            cout.width(7);
            cout.precision(2);
            cout.unsetf(ios::left);
            cout << m_price<<" | ";
            if (m_taxed)  //determining if item is taxed
            {
                cout << "Yes |" << endl;
            }
            else 
            {
                cout << "No  |" << endl;
            }
        }
        else
        {
            printf("| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |\n");
        }
    }

    /*
    isValid()- checking if an Item has valid data present in it
    */
    bool Item::isValid() const
    {
        bool checks = true;
        if(m_itemName[0] == '\0')
        {
            checks = false;
        }
        else if (m_price <= 0)
        {
            checks = false;
        }
        return checks;
    }

    /*
    price()- returns the Item price
    */
    double Item::price() const
    {
        return m_price;
    }

    /*
    tax()- returns tax on an Item, calculated based on the m_taxed flag
    */
    double Item::tax() const
    {
        return m_taxed?price() * (TAX_PERCENT):0;
    }
}