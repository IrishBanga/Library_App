/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "HtmlText.h"
#include "cstring.h"
namespace sdds 
{
	HtmlText::HtmlText(const char* filename, const char* title):Text(filename)
	{
		if (title != nullptr)
		{
			m_title = new char[strLen(title) + 1];
			strCpy(m_title,title);
		}
	}

	HtmlText::HtmlText(HtmlText& original)
	{
		*this = original;
	}

	HtmlText& HtmlText::operator=(HtmlText& original)
	{
		Text::operator=(original);
		if (this != &original)
		{
			delete[] m_title;
			m_title = nullptr;
			if (original.m_title)
			{
				m_title = new char[strLen(original.m_title) + 1];
				strCpy(m_title, original.m_title);
			}
		}
		return *this;
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
	}

	void HtmlText::write(std::ostream& os) const
	{
		bool MS = false;
		os << "<html><head><title>";
		(m_title != nullptr) ? os <<m_title : os <<"No Title";
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}
		char temp = 'x';
		for (int i = 0; Text::operator[](i) != '\0'; i++)
		{
			temp = Text::operator[](i);
			if(temp==' ')
			{
				if (MS == true)
				{
					os << "&nbsp;";
				}
				else
				{
					MS = true;
					os << temp;
				}
			}
			else
			{
				MS = false;
				if (temp == '<')
				{
					os << "&lt;";
				}
				else if (temp == '>')
				{
					os << "&gt;";
				}
				else if (temp == '\n')
				{
					os << "<br />\n";
				}
				else
				{
					os << temp;
				}
			}
		}
		os << "</body>\n</html>";
	}
}