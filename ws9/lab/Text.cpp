/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds 
{
    int Text::getFileLength() const 
    {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    const char& Text::operator[](int index) const
    {
        return m_content[index];
    }

    Text::Text(const char* filename)
    {
        if (filename)
        {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
    }

    Text::Text(Text& original)
    {
        *this = original;
    }

    Text& Text::operator=(Text& original)
    {
        if (this != &original)
        {
            delete[] m_filename;
            m_filename = nullptr;
            delete[] m_content;
            m_content = nullptr;
            if (original.m_filename)
            {
                m_filename = new char[strLen(original.m_filename) + 1];
                strCpy(m_filename, original.m_filename);
            }
            if (original.m_content)
            {
                m_content = new char[strLen(original.m_content) + 1];
                strCpy(m_content, original.m_content);
            }
        }
        return *this;
    }

    Text::~Text()
    {
        delete[] m_content;
        delete[] m_filename;
    }

    void Text::read()
    {
        ifstream fin(m_filename);
        int len = getFileLength();
        m_content = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            fin.get(m_content[i]);
        }
        m_content[len] = '\0';
    }

    void Text::write(std::ostream& os) const
    {
        if (m_content!=nullptr)
        {
            os << m_content;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Text& text)
    {
        text.write(os);
        return os;
    }
}