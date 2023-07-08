/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.h
Version 1.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/08  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds
{
    int getInt(void);
    int getIntMM(int min, int max);
    int getMMInt(int min, int max, const char valueName[], bool infoFlag = false);
    void flushKey();
    void strCpy(char* des, const char* src);
    void strnCpy(char* des, const char* src, int len);
    int strCmp(const char* s1, const char* s2);
    int strnCmp(const char* s1, const char* s2, int len);
    int strLen(const char* s);
    const char* strStr(const char* str1, const char* str2);
    void strCat(char* des, const char* src);
}
#endif // !SDDS_UTILS_H

