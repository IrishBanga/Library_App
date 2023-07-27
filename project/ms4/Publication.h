/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.h
Version 1.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/21  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include "Streamable.h"
#include "Date.h"
#include "Lib.h"
namespace sdds
{
	class Publication :
		    public Streamable
	{
        char* m_title{ nullptr };
        char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
        int m_membership{ 0 };
        int m_libRef{ -1 };
        Date m_date;

    public:
        Publication() {};
        Publication(const Publication& orignial);
        Publication& operator=(const Publication& original);
        ~Publication();

        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
        virtual char type()const;
        bool onLoan()const;
        Date checkoutDate()const;
        bool operator==(const char* title)const;
        operator const char* ()const;
        int getRef()const;

        bool conIO(const std::ios& io) const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
        operator bool() const;
    };
}
#endif // !SDDS_PUBLICATION_H