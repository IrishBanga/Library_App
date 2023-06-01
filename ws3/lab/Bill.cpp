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
    /*
    totalTax()- calculates the total tax amount by iterating through all the items
    */
    double Bill::totalTax() const
    {
        double total = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            total += m_items[i].tax();
        }
        return total;
    }

    /*
    totalPrice()- calculates the total amount by iterating through all the items
    */
    double Bill::totalPrice() const
    {
        double total = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            total += m_items[i].price();
        }
        return total;
    }

    /*
    Title()- used to print a title for the bill based on validity of items in the bill 
    */
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

    /*
    footer()- used to print a footer for the bill based on validity of items in the bill
    */
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

    /*
    setEmpty()- sets the bill to an empty/safe state
    */
    void Bill::setEmpty()
    {
        strCpy(m_title, "\0");
        m_items = nullptr;
    }

    /*
    isValid()- checks for the validity of the Bill data members and the Item objects array 
    */
    bool Bill::isValid() const
    {
        bool checks = true;
        if (m_title == NULL  )
        {
            checks = false;
        }
        else if (m_items == nullptr)  //checking if the Item objects array is pointing to a valid memory address
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
                    checks = false;  //setting the flag to false if any item in the bill is invalid
                }
            }
        }
        return checks;
    }

    /*
    init()- used to initiate a valid Bill with the title(parameter) and allocating dynamic memory based on number of items 
    */
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
            m_items = new Item[m_noOfItems];  //allocating dynamic memory for array of Item objects
        }
        else
        {
            setEmpty(); //setting bill to empty state if the checks fail
        }
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].setEmpty(); //setting all the Item array objects to an empty/safe state
        }
    }

    /*
    add()- adds an item to the Item objects array 
    */
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

    /*
    display()- uses Title(),Item::display(), and, footer() functions to generate a bill
    */
    void Bill::display() const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    /*
    deallocate()- deallocates dynamic memory allocated in the program
    */
    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }
}