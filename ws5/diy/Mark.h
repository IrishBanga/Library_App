/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-15

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds 
{
    class Mark 
    {
        int marks;
        char grade;
        double scale;
        void setEmpty();
        void setInValid();
        Mark& setSMG(int);
    public:
        Mark();
        Mark(int number);
        operator int() const;
        operator double() const;
        operator char() const;
        operator bool() const;
        Mark& operator=(int);
        Mark& operator+=(int);
    };
    int operator+=(int&, const Mark&);
}
#endif // !SDDS_MARK_H
