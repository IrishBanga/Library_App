/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include "Text.h"
namespace sdds 
{
    class HtmlText : public Text
    {
        char* m_title{};
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(HtmlText&);
        HtmlText& operator=(HtmlText&);
        ~HtmlText();
        void write(std::ostream& os)const;
    };
}
#endif // !SDDS_HTMLTEXT_H
