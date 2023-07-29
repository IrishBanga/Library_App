/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/21  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/
#include "Streamable.h"
namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const Streamable& display)
	{
		if (display)
		{
			display.write(ostr);
		}
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Streamable& read)
	{
		read.read(istr);
		return istr;
	}
}