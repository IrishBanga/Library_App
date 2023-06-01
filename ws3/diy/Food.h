/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-01

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds {
	class Food {
		char name[31];  // holds the item name up to 30 chars
		int calories;
		int mealTime;
		void setName(const char* name);
	public:
		void setEmpty();
		void set(const char* name, int calories, int when);
		void display()const;
		bool isValid()const;
		int retCalories()const;
		int meal()const;
	};
}

#endif // !SDDS_FOOD_H
