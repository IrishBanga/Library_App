/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-01

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;

namespace sdds
{
	/*
	totalCalories()- calculates the total calories by iterating through all the Food items
	*/
	int CalorieList::totalCalories() const
	{
		int total = 0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			total += m_items[i].retCalories();
		}
		return total;
	}

	/*
	Title()- used to print a title for the bill based on validity of Food items in the bill
	*/
	void CalorieList::Title() const
	{
		cout << "+----------------------------------------------------+" << endl;
		if (isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+\n"
			"| Food name                      | Cals | When       |\n"
			"+--------------------------------+------+------------+" << endl;
	}

	/*
	footer()- used to print a footer for the bill based on validity of Food items in the bill
	*/
	void CalorieList::footer() const
	{
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid())
		{
			cout << "|    Total Calories for today: ";
			cout.width(8);
			cout.setf(ios::right);
			cout << totalCalories();
			cout << " |            |\n";
		}
		else
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	/*
	setEmpty()- sets the CalorieList to an empty/safe state
	*/
	void CalorieList::setEmpty()
	{
		m_items = nullptr;
	}

	/*
	isValid()- checks for the validity of CalorieList data members and the Food objects array
	*/
	bool CalorieList::isValid() const
	{
		bool checks = true;
		if (m_items == nullptr)
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
					checks = false;  //setting the flag to false if any item in the list is invalid
				}
			}
		}
		return checks;
	}

	/*
	init()- used to initiate a valid CalorieList(Food items array) with dynamic memory allocation based on (size)
	*/
	void CalorieList::init(int size)
	{
		bool valid = true;
		if (size < 1)
		{
			valid = false;
		}
		if (valid)
		{
			m_noOfItems = size;
			m_itemsAdded = 0;
			m_items = new Food[m_noOfItems];
		}
		else
		{
			setEmpty();
		}
		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].setEmpty();  //setting all the Food array objects to an empty/safe state
		}
	}

	/*
	add()- adds an item to the Food objects array
	*/
	bool CalorieList::add(const char* item_name, int calories, int when)
	{
		bool check = false;
		if (m_itemsAdded < m_noOfItems)
		{
			check = true;
			m_items[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded++;
		}
		return check;
	}

	/*
	display()- uses Title(),Food::display(), and, footer() functions to generate a bill
	*/
	void CalorieList::display() const
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
	void CalorieList::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}