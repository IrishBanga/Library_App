/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-09

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds
{
	class Label 
	{
		char frame[8 + 1]; //holds the frame schema
		char* content;  //holds the content to be printed in frame
		void setToDefault();
		void setFrame(const char* str);
	public:
		void clear();
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* frameContent);
		~Label();
		void readLabel();
		std::ostream& printLabel() const;
		void line(char start, char middle, char last, int length) const;  //custom function to print a patterned line
		void pattern(char leftTop, char top, char topRight, char right, char rightBottom, char bottom, char bottomLeft, char left, char fill, char* content, int width, int height) const;  //custom function that uses line() to print a specific pattern
	};
}
#endif // !SDDS_LABEL_H
