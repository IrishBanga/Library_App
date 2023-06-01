/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-01

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"

namespace sdds
{
	class CalorieList {
		Food* m_items;  //a dynamic array for holding Food objects
		int m_noOfItems;  //used to allocate dynamic memory to the array of Food objects
		int m_itemsAdded;  //keeps track of items being added
		int totalCalories()const;
		void Title()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;
	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();
	};
}

#endif // !SDDS_CALORIELIST_H
