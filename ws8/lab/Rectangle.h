/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds
{
    class Rectangle :
        public LblShape
    {
        int m_width{};
        int m_height{};
    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void draw(std::ostream& os)const;
        void line(char start, char middle, char last, int length) const;
        void getSpecs(std::istream& in);
    };
}
#endif // !SDDS_RECTANGLE_H




