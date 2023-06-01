/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-01

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;

namespace sdds
{
	/*
	setName()- sets the food name to the parameter passed(if not NULL) upto 30 characters only
	*/
	void Food::setName(const char* name)
	{
		if (name != NULL)
		{
			strnCpy(Food::name, name, 30);
		}
	}

	/*
	setEmpty()- sets Food data members to a recognizable safe Empty State.
	*/
	void Food::setEmpty()
	{
		name[0] = '\0';
		calories = -1;
	}

	/*
	set()- sets Food's data members to the arguments passed
	*/
	void Food::set(const char* name, int calories, int when)
	{
		setName(name);
		Food::calories = calories;
		Food::mealTime = when;
	}

	/*
	display()- displays Food information in a specific format
	*/
	void Food::display() const
	{
		if (isValid())
		{
			cout << "| ";
			cout.fill('.');
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(30);
			cout << name << " | ";
			cout.fill(' ');
			cout.width(4);
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout << retCalories() << " | ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(10);
			switch (meal()) 
			{
			case 1:
				cout << "Breakfast";
				break;
			case 2:
				cout << "Lunch";
				break;
			case 3:
				cout << "Dinner";
				break;
			case 4:
				cout << "Snack";
				break;
			}
			cout << " |" << endl;
		}
		else
		{
			printf("| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |\n");
		}
		cout.unsetf(ios::left);
	}

	/*
	isValid()- checking if a Food object has valid data present in it
	*/
	bool Food::isValid() const
	{
		bool checks = true;
		if (name[0] == '\0')
		{
			checks = false;
		}
		else if (calories <= 0 || calories > 3000)
		{
			checks = false;
		}
		else if (mealTime < 1 || mealTime>4)
		{
			checks = false;
		}
		return checks;
	}

	/*
	retCalories()- returns the calories from a Food item
	*/
	int Food::retCalories() const
	{
		return calories;
	}

	/*
	meal()- returns mealTime (an integer based on time of meal)
	*/
	int Food::meal() const
	{
		return mealTime;
	}
}