/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-08-05

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "ReadWrite.h"
namespace sdds {
   class Car : public ReadWrite {
      char m_plate[9];
      char m_makeModel[41];
   public:
      Car(const char* plate = "", const char* makeModel = "");
      void set(const char* plate, const char* makeModel);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(const char* mmSubstr)const;
   };


}
#endif // !SDDS_CAR_H_
