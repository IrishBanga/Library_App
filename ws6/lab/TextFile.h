/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-05

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TEXTFILE_H
#define SDDS_TEXTFILE_H
#include <iostream>
namespace sdds
{
	class TextFile;
	class Line
	{
		char* m_value{ nullptr };
		operator const char* ()const;
		Line();
		Line& operator=(const char*);
		~Line();
		friend class TextFile;
		Line(Line&) = delete;
		Line& operator=(Line&) = delete;
	};

	class TextFile
	{
		Line* m_textLines;
		char* m_filename;
		unsigned m_noOfLines;
		unsigned m_pageSize;
		void setFilename(const char* fname, bool isCopy = false);
		void setNoOfLines();
		void loadText();
		void saveAs(const char* fileName)const;
		void setEmpty();
		void init();
	public:
		TextFile(unsigned pageSize = 15);
		TextFile(const char* filename, unsigned pageSize = 15);
		TextFile(const TextFile&);
		TextFile& operator=(const TextFile&);
		~TextFile();
		std::ostream& view(std::ostream& ostr)const;
		std::istream& getFile(std::istream& istr);
		operator bool()const;
		unsigned lines()const;
		const char* name()const;
		const char* operator[](unsigned index)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
	std::istream& operator>>(std::istream& istr, TextFile& text);
}
#endif // !SDDS_TEXTFILE_H
