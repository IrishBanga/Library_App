/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-05

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
	Line::Line()
	{
		m_value = nullptr;
	}

	Line::operator const char* () const 
	{
		return (const char*)m_value;
	}

	Line& Line::operator=(const char* lineValue) 
	{
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}

	Line::~Line() 
	{
		delete[] m_value;
	}

	void TextFile::setFilename(const char* fname, bool isCopy)
	{
		delete[] m_filename;
		m_filename = nullptr;
		if (isCopy)
		{
			m_filename = new char[strLen(fname) + 1 + 2 + 1];
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
		else
		{
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
	}

	void TextFile::setNoOfLines()
	{
		ifstream file(m_filename);
		if (file.is_open())
		{
			char ch = '\0';
			while (file.get(ch))
			{
				if (ch == '\n')
				{
					m_noOfLines++;
				}
			}
			if (m_noOfLines == 0)
			{
				setEmpty();
			}
			else if (ch != '\0')
			{
				m_noOfLines++;
			}
		}
		file.close();
	}

	void TextFile::loadText()
	{
		if (m_filename)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
			m_textLines = new Line[m_noOfLines];
			int i = 0;
			string lineContent;
			ifstream file(m_filename);
			while (file.is_open() && getline(file, lineContent))
			{
				m_textLines[i].m_value = new char[lineContent.length() + 1];
				strCpy(m_textLines[i].m_value, lineContent.c_str());
				i++;
			}
			m_noOfLines = i;
			file.close();
		}
	}

	void TextFile::saveAs(const char* fileName)const
	{
		ofstream fileout(fileName);
		for (unsigned int i = 0; i < m_noOfLines; i++)
		{
			fileout << m_textLines[i] << '\n';
		}
		fileout.close();
	}

	void TextFile::init()
	{
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	void TextFile::setEmpty()
	{
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	TextFile::TextFile(unsigned pageSize)
	{
		init();
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize)
	{
		init();
		m_pageSize = pageSize;
		if (filename != nullptr)
		{
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile::TextFile(const TextFile& original)
	{
		init();
		m_pageSize = original.m_pageSize;
		if (original)
		{
			setFilename(original.m_filename, true);
			original.saveAs(m_filename);
			m_noOfLines = original.m_noOfLines;
			loadText();
		}
	}

	TextFile& TextFile::operator=(const TextFile& original)
	{
		if (*this && original)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
			original.saveAs(m_filename);
			m_noOfLines = original.m_noOfLines;
			loadText();
		}
		return *this;
	}

	TextFile::~TextFile()
	{
		setEmpty();
	}

	std::ostream& TextFile::view(std::ostream& ostr)const
	{
		if (*this)
		{
			ostr << m_filename << endl;
			for (int i = 0; i < strLen(m_filename); i++)
			{
				ostr << "=";
			}
			ostr << endl;
			unsigned int i = 0, j = 0;
			bool done = false;
			while (!done)
			{
				for (i = j; i < m_pageSize + j && i < m_noOfLines; i++)
				{
					ostr << m_textLines[i] << endl;
				}
				j = i;
				if (i == m_noOfLines)
				{
					done = true;
				}
				else
				{
					char ch = '\0';
					ostr << "Hit ENTER to continue...";
					cin.get(ch);
					if (ch == '\n')
					{
						done = false;
					}
					else
					{
						done = true;
						i = m_noOfLines;
					}
				}

			}
		}
		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr)
	{
		string Name;
		istr >> Name;
		while (getchar() != '\n');
		setFilename(Name.c_str());
		setNoOfLines();
		loadText();
		return istr;
	}

	const char* TextFile::operator[](unsigned index)const
	{
		const char* res = nullptr;
		if (*this)
		{
			res = m_textLines[index % m_noOfLines];
		}
		return res;
	}

	TextFile::operator bool()const
	{
		return(m_filename != nullptr && m_noOfLines != 0 && m_textLines != nullptr);
	}

	unsigned TextFile::lines()const
	{
		return m_noOfLines;
	}

	const char* TextFile::name()const
	{
		return (const char*)m_filename;
	}

	ostream& operator<<(ostream& ostr, const TextFile& text)
	{
		text.view(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, TextFile& text)
	{
		text.getFile(istr);
		return istr;
	}

}