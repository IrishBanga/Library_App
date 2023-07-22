/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds
{
	class Line :
		public LblShape
	{
		int m_length{0};
	public:
		Line();
		Line(const char* line, int length);
		void draw(std::ostream& os)const;
		void getSpecs(std::istream& in);
	};
}
#endif // !SDDS_LINE_H


