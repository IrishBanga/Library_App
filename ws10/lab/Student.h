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
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "ReadWrite.h"
namespace sdds {
   class Student : public ReadWrite {
      int m_stno;
      char m_name[41];
      double m_gpa;
   public:
      Student();
      Student(int stno, const char* name, double gpa);
      void set(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(double gpa)const;
   };
}
#endif // !SDDS_STUDENT_H_

