/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
Version 1.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/26  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
namespace sdds
{
	class Book :
		public Publication
	{
        char* m_author{ nullptr };

    public:
        Book() :Publication() {};
        Book(const Book& original);
        Book& operator=(const Book& original);
        ~Book();

        void set(int member_id);
        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
        operator bool() const;
	};
}
#endif // !SDDS_BOOK_H

