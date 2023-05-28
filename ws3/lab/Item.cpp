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
    void Item::setName(const char* name)
    {
        if (name != NULL)
        {
            strnCpy(m_itemName, name, 20);
        }
    }

    void Item::setEmpty()
    {
        m_itemName[0] = '\0';
        m_price = -1;
    }

    void Item::set(const char* name, double price, bool taxed)
    {
        setName(name);
        m_price = price;
        m_taxed = taxed;
    }

    void Item::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.fill('.');
            cout.width(20);
            cout.setf(ios::left);
            cout << m_itemName<<" | ";
            cout.fill(' ');
            cout.setf(ios::fixed);
            cout.width(7);
            cout.precision(2);
            cout.unsetf(ios::left);
            cout << m_price<<" | ";
            if (m_taxed) 
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

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        return m_taxed?price() * (TAX_PERCENT):0;
    }
}