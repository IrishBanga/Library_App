/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-18
Last Modified : 2023-05-28

Revision History
-----------------------------------------------------------
Date        Reason
2023-05-28  modified strnCpy() - null termination issue
-----------------------------------------------------------

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "cstring.h"

namespace sdds
{
    void strCpy(char* des, const char* src)
    {
        int size = strLen(src);
        int i;
        for (i = 0; i < size; i++)
        {
            des[i] = src[i];
        }
        des[size] = '\0';
    }
    
    void strnCpy(char* des, const char* src, int len)
    {
        int i;
        int done = 0;
        for (i = 0; i < len && done == 0; i++)
        {

            if (src[i] != '\0')
            {
                des[i] = src[i];
            }
            else
            {
                des[i] = '\0';
                done = 1;
            }
        }
        des[i] = '\0';
    }
    
    int strCmp(const char* s1, const char* s2)
    {
        int size_s1 = strLen(s1);
        int size_s2 = strLen(s2);
        int i;
        int res=0;
        for (i = 0; i < ((size_s1 > size_s2) ? size_s2 : size_s1)&&res==0; i++)
        {
            if (s1[i] > s2[i])
            {
                res = 1;
            }
            else if (s2[i] > s1[i])
            {
                res = -1;
            }
            else if (s2[i] == s1[i])
            {
                res = 0;
            }
        }
        if (size_s1 != size_s2 && res == 0)
        {
            res = (size_s1 > size_s2) ? 1 : -1;
        }
        return res;
    }
    
    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i;
        int res=0;
        for (i = 0; res == 0 && i < len; i++)
        {
            if (s1[i] > s2[i])
            {
                res = 1;
            }
            else if (s2[i] > s1[i])
            {
                res = -1;
            }
            else if (s2[i] == s1[i])
            {
                res = 0;
            }
        }
        return res;
    }
    
    int strLen(const char* s)
    {
        int i = 0;
        while (s[i] != '\0')
        {
            i++;
        }
        return i;
    }
    
    const char* strStr(const char* str1, const char* str2)
    {
        int len = strLen(str1);
        int i;
        int index=0;
        int done = 0;
        for (i = 0; done == 0 && i < len; i++)
        {
            if (str1[i] == str2[0])
            {
                int res;
                res = strnCmp(str1 + i, str2, strLen(str2));
                if (res== 0)
                {
                    index= i;
                    done = 1;
                }
            }
        }
        return done ? str1 + index:nullptr;
    }
    
    void strCat(char* des, const char* src)
    {
        int i = 0;
        while (des[i] != '\0')
        {
            i++;
        }
        int j;
        for (j = 0; j < strLen(src); j++)
        {
            des[i] = src[j];
            i++;
        }
        des[i] = '\0';
    }

}