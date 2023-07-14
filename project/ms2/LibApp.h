/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.h
Version 1.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/14  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds 
{
   class LibApp 
   {
       bool m_changed{false};
       Menu m_mainMenu{ "Seneca Library Application" };
       Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
       bool confirm(const char* message);
       void load(); 
       void save();  
       void search();  
       void returnPub();
       void footer();
   public:
       LibApp();
       ~LibApp();
       void newPublication();
       void removePublication();
       void checkOutPub();
       void run();
   };
}
#endif // !SDDS_LIBAPP_H



