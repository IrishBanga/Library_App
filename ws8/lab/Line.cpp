/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>
#include "Line.h"
namespace sdds
{
	Line::Line():LblShape(), m_length(0)
	{
	}
	Line::Line(const char* line, int length):LblShape(line), m_length(length)
	{
	}

	void Line::draw(std::ostream& os) const
	{
		if (m_length != 0 && label()!=nullptr)
		{
			os << label();
			os << std::endl;
			for (int i = 0; i < m_length; i++)
			{
				os << "=";
			}
		}
	}

	void Line::getSpecs(std::istream& in)
	{
		LblShape::getSpecs(in);
		in >> m_length;
		in.ignore();
	}
}
