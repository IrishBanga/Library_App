/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.cpp
Version 1.1
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/21  Preliminary release
2023/07/26  v1.1 - modified write() to print title in fixed 
            width(SDDS_TITLE_WIDTH)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/
#include "Publication.h"
#include "Utils.h"
namespace sdds
{
    Publication::Publication(const Publication& original) 
    {
        *this = original;
    }

    Publication& Publication::operator=(const Publication& original) 
    {
        if (this != &original) 
        {
            delete[] m_title;
            m_title = nullptr;
            if (original.m_title != nullptr) 
            {
                m_title = new char[strLen(original.m_title) + 1];
                strCpy(m_title, original.m_title);
            }
            strCpy(m_shelfId, original.m_shelfId);
            m_membership = original.m_membership;
            m_libRef = original.m_libRef;
            m_date = original.m_date;
        }
        return *this;
    }

    Publication::~Publication() 
    {
        delete[] m_title;
    }

    void Publication::set(int member_id) 
    {
        m_membership = member_id;
    }

    void Publication::setRef(int value) 
    {
        m_libRef = value;
    }

    void Publication::resetDate() 
    {
        m_date = Date();
    }

    char Publication::type() const 
    {
        return 'P';
    }

    bool Publication::onLoan() const 
    {
        return (m_membership != 0);
    }

    Date Publication::checkoutDate() const 
    {
        return m_date;
    }

    bool Publication::operator==(const char* title) const 
    {
        return (strStr(m_title, title) != nullptr);
    }

    Publication::operator const char* () const 
    {
        return m_title;
    }

    int Publication::getRef() const
    {
        return m_libRef;
    }

    bool Publication::conIO(const std::ios& io) const
    {
        return (&io == &std::cin || &io == &std::cout);
    }

    std::ostream& Publication::write(std::ostream& os) const 
    {
        if (conIO(os)) 
        {
            os << "| ";
            os.width(SDDS_SHELF_ID_LEN);
            os << m_shelfId << " | ";
            os.unsetf(std::ios::right);
            os.setf(std::ios::left);
            os.fill('.');
            os.width(SDDS_TITLE_WIDTH);
            if(strLen(m_title) <= SDDS_TITLE_WIDTH)
            {
                os << m_title;
            }
            else
            {
                char temp[SDDS_TITLE_WIDTH + 1];
                strnCpy(temp, m_title, SDDS_TITLE_WIDTH);
                os << temp;
            }
            os << " | ";
            os.fill(' ');
            if (m_membership != 0)
            {
                os << m_membership;
            }
            else
            {
                os << " N/A ";
            }
            os << " | " << m_date << " |";
        }
        else 
        {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
        }
        return os;
    }

    std::istream& Publication::read(std::istream& in) 
    {
        char tempShelfId[SDDS_SHELF_ID_LEN + 1];
        char tempTitle[SDDS_MAX_TITLE_LENGTH + 1];
        int tempMembership = 0;
        int tempLibRef = -1;
        Date tempDate;

        delete[] m_title;
        m_title = nullptr;
        m_membership = 0;
        m_libRef = -1;
        if (conIO(in)) 
        {
            std::cout << "Shelf No: ";
            in.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1);
            if (in.fail() || strLen(tempShelfId) != SDDS_SHELF_ID_LEN) 
            {
                in.setstate(std::ios_base::failbit);
            }
            std::cout << "Title: ";
            in.getline(tempTitle, SDDS_MAX_TITLE_LENGTH + 1);
            std::cout << "Date: ";
            in >> tempDate;
            if (!tempDate)
            {
                in.setstate(std::ios_base::failbit);
            }
        }
        else {
            in >> tempLibRef;
            in.ignore();
            in.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1,'\t');
            in.getline(tempTitle, SDDS_MAX_TITLE_LENGTH + 1, '\t');
            in >> tempMembership;
            in.ignore();
            in >> tempDate;
            if (!tempDate)
            {
                in.setstate(std::ios_base::failbit);
            }
        }
        if (!in.fail())
        {
            m_title = new char[strLen(tempTitle) + 1];
            strCpy(m_title, tempTitle);
            strCpy(m_shelfId, tempShelfId);
            m_date = tempDate;
            m_libRef = tempLibRef;
            m_membership = tempMembership;
        }
        return in;
    }

    Publication::operator bool() const
    {
        return ((m_title != nullptr) && (strCmp(m_shelfId, "") != 0));
    }

}