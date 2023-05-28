/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds 
{
    double Bill::totalTax() const
    {
        double total = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            total += m_items[i].tax();
        }
        return total;
    }

    double Bill::totalPrice() const
    {
        double total = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            total += m_items[i].price();
        }
        return total;
    }

    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;
        if(isValid())
        {
            cout << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << m_title << " |"<<endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+\n"
                "| Item Name            | Price   + Tax |\n"
                "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.precision(2);
            cout.setf(ios::fixed);
            cout.width(10);
            cout << totalTax()<<" |"<<endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout << totalPrice() << " |"<<endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << totalTax()+totalPrice() << " |"<<endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty()
    {
        strCpy(m_title, "\0");
        m_items = nullptr;
    }

    bool Bill::isValid() const
    {
        bool checks = true;
        if (m_title == NULL  )
        {
            checks = false;
        }
        else if (m_items == nullptr)
        {
            checks = false;
        }
        else if (m_noOfItems < 1)
        {
            checks = false;
        }
        else
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                bool valid = true;
                valid = m_items[i].isValid();
                if (!valid)
                {
                    checks = false;
                }
            }
        }
        return checks;
    }

    void Bill::init(const char* title, int noOfItems)
    {
        bool valid = true;
        if (title == NULL|| strLen(title) == 0)
        {
            valid = false;
        }
        if(noOfItems < 1)
        {
            valid = false;
        }
        if (valid)
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[m_noOfItems];
        }
        else
        {
            setEmpty();
        }
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].setEmpty();
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        bool check = false;
        if (m_itemsAdded < m_noOfItems)
        {
            check = true;
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            
        }
        return check;
    }

    void Bill::display() const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }
}