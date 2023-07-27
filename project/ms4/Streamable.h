/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streamable.h
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
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds
{
	class Streamable
	{
	public:
		virtual bool conIO(const std::ios& io) const = 0;
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& in) = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable(){}
	};
	std::ostream& operator<<(std::ostream& ostr, const Streamable& draw);
	std::istream& operator>>(std::istream& istr, Streamable& read);
}
#endif // !SDDS_STREAMABLE_H

