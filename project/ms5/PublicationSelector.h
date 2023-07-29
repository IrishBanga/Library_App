/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 5
Module: PublicationSelector
Filename: PublicationSelector.h
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/26  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/
#ifndef SDDS_PUBLICATIONSELECTOR_H
#define SDDS_PUBLICATIONSELECTOR_H
#include "Publication.h"
namespace sdds {
   class PublicationSelector {
      const int allocationUnit{ 10 };
      const int m_pageSize{ };
      const Publication** m_pub{};
      char m_title[81]{};
      int m_currentPage{ 1 };
      int m_arraySize{};
      int m_noOfPubs{};
      void display(int page)const;
      int getSelectedLibRef()const;
   public:
      PublicationSelector(const char* title = "Select a publication: ", int pageSize = 15);
      ~PublicationSelector();
      PublicationSelector(const PublicationSelector&) = delete;
      PublicationSelector& operator=(const PublicationSelector&) = delete;
      PublicationSelector& operator<<(const Publication* pub);
      PublicationSelector& operator<<(const Publication& pub);
      operator bool()const;
      void reset(); 
      void sort();
      int run();
   };
}
#endif // !SDDS_PUBLICATIONSELECTOR_H