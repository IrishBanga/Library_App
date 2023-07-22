/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds
{
	class Shape
	{
	public:
		virtual void draw(std::ostream& os)const = 0;
		virtual void getSpecs(std::istream& in) = 0;
		virtual ~Shape() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& draw);
	std::istream& operator>>(std::istream& istr, Shape& read);
}
#endif // !SDDS_SHAPE_H


