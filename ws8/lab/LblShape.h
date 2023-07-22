/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds
{
	class LblShape :
		public Shape
	{
		char* m_label{ nullptr };
	protected:
		const char* label()const;
	public:
		LblShape() {};
		LblShape(const char* label);
		LblShape(LblShape&) = delete;
		LblShape& operator=(LblShape&) = delete;
		void getSpecs(std::istream& in);
		virtual ~LblShape();
	};
}
#endif // !SDDS_LBLSHAPE_H



