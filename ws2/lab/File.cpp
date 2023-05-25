/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-25

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds 
{
   FILE* fptr;
   bool openFile(const char filename[]) 
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() 
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) 
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() 
   {
      if (fptr) fclose(fptr);
   }

   bool read(int &empNo) 
   {
       return 1 == fscanf(fptr, "%d,",&empNo);
   }

   bool read(double &salary) 
   {
       return 1 == fscanf(fptr, "%lf,", &salary);
   }

   bool read(char* str)
   {
       return 1 == fscanf(fptr, "%[^\n]\n", str);
   }
}

