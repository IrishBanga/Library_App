/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-25

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"  
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds 
{
   int noOfEmployees;
   Employee* employees;
   void sort() 
   {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   bool load(Employee* recEmployee) 
   {
      bool ok = false;
      char name[128];
      if (read(recEmployee->m_empNo) && read(recEmployee->m_salary) && read(name))
      { 
          recEmployee->m_name = new char[strLen(name) + 1];
          strCpy(recEmployee->m_name, name);
         ok = true;
      }
      return ok;
   }
   
   bool load() 
   {
      bool ok = false;
      if (openFile(DATAFILE)) 
      {
          noOfEmployees =noOfRecords();
          employees = new Employee[noOfEmployees]; 
          int reads=0;
          for (int i = 0; i < noOfEmployees; i++)
          {
              reads+=load(&employees[i]);
          }
          if (reads!=noOfEmployees)
          {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          }
          else
          {
              ok = true;
              closeFile();
          }
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   void display()
   {
       sort();
       cout << "Employee Salary report, sorted by employee number\n"
           "no- Empno, Name, Salary\n"
           "------------------------------------------------" << endl;
       for(int i=0;i<noOfEmployees;i++)
       {
           cout<< i+1 <<"- " << employees[i].m_empNo <<": " << employees[i].m_name<<", " << employees[i].m_salary << endl;
       }
   }
   
   void deallocateMemory()
   {
       for (int i = 0; i < noOfEmployees; i++)
       {
          delete[] employees[i].m_name;
          employees[i].m_name=nullptr;
       }
       delete[] employees;
       employees = nullptr;
   }
}