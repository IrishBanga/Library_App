/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 4
Module: Book
Filename: Book.cpp
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
#include "Book.h"
#include "Utils.h"
namespace sdds
{
    Book::Book(const Book& original) :Publication(original)
    {
        *this = original;
    }
    
	Book& Book::operator=(const Book& original)
	{
		if (this != &original)
		{
            Publication::operator=(original);
			delete[] m_author;
            m_author = nullptr;
			if (original.m_author != nullptr)
			{
                m_author = new char[strLen(original.m_author) + 1];
				strCpy(m_author, original.m_author);
			}
		}
		return *this;
	}

	Book::~Book()
	{
        delete[] m_author;
	}

	void Book::set(int member_id)
	{
        Publication::set(member_id);
        resetDate();
	}

	char Book::type() const
	{
        return 'B';
	}
    
	std::ostream& Book::write(std::ostream& os) const
	{
        Publication::write(os);
        if (conIO(os))
        {
            os << " ";
            os.width(SDDS_AUTHOR_WIDTH);
            if (strLen(m_author) <= SDDS_AUTHOR_WIDTH)
            {
                os << m_author;
            }
            else
            {
                char temp[SDDS_AUTHOR_WIDTH + 1];
                strnCpy(temp, m_author,SDDS_AUTHOR_WIDTH);
                os << temp;
            }
            os << " |";
        }
        else
        {
            os << "\t" << m_author;
        }
        return os;
	}

	std::istream& Book::read(std::istream& in)
	{
        Publication::read(in);
        char tempAuthor[SDDS_MAX_TITLE_LENGTH + 1];
        delete[] m_author;
        m_author = nullptr;
        if (conIO(in))
        {
            in.ignore();
            std::cout << "Author: ";
            in.getline(tempAuthor, SDDS_MAX_TITLE_LENGTH + 1);
        }
        else
        {
            in.ignore();
            in.get(tempAuthor,SDDS_MAX_TITLE_LENGTH+1,'\n');
        }
        if (!in.fail())
        {
            m_author = new char[strLen(tempAuthor) + 1];
            strCpy(m_author, tempAuthor);
        }
        return in;
    }

	Book::operator bool() const
	{
        return ((m_author!=nullptr) && (strCmp(m_author, "")!=0) && Publication::operator bool());
	}
}