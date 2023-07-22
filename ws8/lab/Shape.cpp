/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Shape.h"
namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const Shape& draw)
	{
		draw.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& read)
	{
		read.getSpecs(istr);
		return istr;
	}
}
