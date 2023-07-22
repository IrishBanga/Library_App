/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>
#include "Rectangle.h"
namespace sdds
{
	Rectangle::Rectangle():LblShape(), m_width(0),m_height(0)
	{
	}
	Rectangle::Rectangle(const char* label, int width, int height):LblShape(label)
	{
		if (height < 3 || width < (int)(strlen(label) + 2))
		{
			m_width = -1;
			m_height = -1;
		}
		else
		{
			m_width = width;
			m_height = height;
		}
	}
	void Rectangle::draw(std::ostream& os) const
	{
		if (m_height >= 0 && m_width >= 0)
		{
			line('+', '-', '+', m_width);
			os << std::endl;
			os << "|";
			os.width(m_width - 2);
			os.unsetf(std::ios::right);
			os.setf(std::ios::left);
			os << label();
			os.unsetf(std::ios::left);
			os << "|" << std::endl;
			for (int i = 0; i < m_height - 3; i++)
			{
				line('|', ' ', '|', m_width);
				os << std::endl;
			}
			line('+', '-', '+', m_width);
		}
	}

	void Rectangle::line(char left, char fill, char right, int length) const
	{
		int i = 0;
		std::cout << left;
		while (i < (length - 2))
		{
			std::cout << fill;
			i++;
		}
		std::cout << right;
	}

	void Rectangle::getSpecs(std::istream& in)
	{
		LblShape::getSpecs(in);
		
		in >> m_width;
		in.ignore();
		in >> m_height;
		in.ignore();
	}
}
