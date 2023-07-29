/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
Version 2.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/14  Preliminary release
2023/07/29  v2.0 - added m_publicationMenu, m_filename, 
            PPA(Publication Pointers Array), 
            NOLP(Number Of Loaded Publications),
            LLRN(Last Library Reference Number),
            getPub() and deleteDMA() function
            Modified declarations of LibApp() constructor
            and search() function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "PublicationSelector.h"
namespace sdds 
{
   class LibApp 
   {
       bool m_changed{false};
       Menu m_mainMenu{ "Seneca Library Application" };
       Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
       Menu m_publicationMenu{ "Choose the type of publication:" };
       char m_filename[256]{};
       Publication* PPA[SDDS_LIBRARY_CAPACITY]{};
       int NOLP{};
       int LLRN{};
       bool confirm(const char* message);
       void load(); 
       void save();  
       int search(int searchFlag = 0);
       void returnPub();
       void footer();
       Publication* getPub(int libRef);
       void deleteDMA();
   public:
       LibApp(const char* filename);
       ~LibApp();
       void newPublication();
       void removePublication();
       void checkOutPub();
       void run();
   };
}
#endif // !SDDS_LIBAPP_H



