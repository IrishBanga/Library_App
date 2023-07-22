/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "LblShape.h"

namespace sdds
{
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape(const char* label)
	{
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	void LblShape::getSpecs(std::istream& in)
	{
		std::string temp;
		getline(in,temp,',');
		delete[] m_label;
		m_label = new char[temp.length() + 1];
		strcpy(m_label, temp.c_str());
 	}
	LblShape::~LblShape()
	{
		delete[] m_label;
	}
}
