/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-15

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"
using namespace std;

namespace sdds
{
	/*
	setEmpty()- used to set a Mark object to an empty state
	*/
	void Mark::setEmpty()
	{
		marks = 0;
		grade = '\0';
		scale = 0;
	}

	/*
	setInValid()- custom function used to set a Mark object to an invalid state
	*/
	void Mark::setInValid()
	{
		marks = 0;
		grade = 'X';
		scale = 0;
	}

	/*
	setSMG()- custom function used to set a valid mark(M) and corresponding values of grade(G) and scale(S) to a Mark object 
	*/
	Mark& Mark::setSMG(int number)
	{
		if (0 <= number && number < 50)
		{
			marks = number;
			grade = 'F';
			scale = 0.0;
		}
		else if (50 <= number && number < 60)
		{
			marks = number;
			grade = 'D';
			scale = 1.0;
		}
		else if (60 <= number && number < 70)
		{
			marks = number;
			grade = 'C';
			scale = 2.0;
		}
		else if (70 <= number && number < 80)
		{
			marks = number;
			grade = 'B';
			scale = 3.0;
		}
		else if (80 <= number && number <= 100)
		{
			marks = number;
			grade = 'A';
			scale = 4.0;
		}
		else
		{
			setInValid();
		}
		return *this;
	}

	/*
	Mark()- default constructor to initialize a new Mark object
	*/
	Mark::Mark()
	{
		setEmpty();
	}

	/*
	Mark()- Constructor to initialize a valid Mark object
	*/
	Mark::Mark(int number)
	{
		setEmpty();
		*this = setSMG(number);
	}

	/*
	operator bool()- operator to check if a Mark is valid
	*/
	Mark::operator bool() const
	{
		return (grade != 'X') ? true : false;
	}

	/*
	operator int() - operator used to return marks from a Mark object
	*/
	Mark::operator int() const
	{
		return marks;
	}

	/*
	operator double() - operator used to return scale(GPA) from a Mark object
	*/
	Mark::operator double() const
	{
		return scale;
	}

	/*
	operator char() - operator used to return grade(letter Grade) from a Mark object
	*/
	Mark::operator char() const
	{
		return grade;
	}

	/*
	operator=()- operator used to set Mark object(regardless of its validity) to a valid newMark
	*/
	Mark& Mark::operator=(int newMark)
	{
		if (newMark >= 0 && newMark <= 100)
		{
			setSMG(newMark);
		}
		else
		{
			setInValid();
		}
		return *this;
	}

	/*
	operator+=()- operator used to add marks to a valid Mark object
	*/
	Mark& Mark::operator+=(int bonus)
	{
		if (*this && bonus > 0 && (marks + bonus <= 100))
		{
			setSMG(marks + bonus);
		}
		else
		{
			setInValid();
		}
		return *this;
	}

	/*
	operator+=()- helper operator that returns the sum of the value of first and marks of second Mark object(valid)
	*/
	int operator+=(int& first, const Mark& second)
	{
		if(second)
		{
			first += int(second);
		}
		return first;
	}
}