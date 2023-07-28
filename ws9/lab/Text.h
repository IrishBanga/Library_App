/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
namespace sdds 
{
   class Text 
   {
       char* m_filename{};
       char* m_content{};
       int getFileLength()const;
   protected:
       const char& operator[](int index)const;
   public:
       Text(const char* filename = nullptr);
       Text(Text&);
       Text& operator=(Text&);
       virtual ~Text();
       void read();
       virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SDDS_TEXT_H

