/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 4
Module: Date
Filename: Date.cpp
Version 2.0
Author: Fardad Soleimanloo, Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/06/27  Preliminary release (Author: Fardad Soleimanloo)
2023/07/08  Added operator overlaods and helper, read, write 
            functions (Author: Irish Banga)
2023/07/21  v2 - added global variables, removed flushKey() 
            from read() function, modified systemYear() and 
            setToToday() functions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include"Utils.h"
namespace sdds 
{
    /*
    v2 additions - MS3 requirements
    */
    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;

    bool Date::validate()
    {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }

    int Date::mdays()const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }
    
    /*
    v2 systemYear() - modified as per MS3 instructions
    */
    int Date::systemYear()const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }
    /*
    v2 setToToday() - modified as per MS3 instructions
    */
    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }

    int Date::daysSince0001_1_1()const 
    { 
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }

    Date::Date() :m_CUR_YEAR(systemYear()) 
    {
        setToToday();
    }
    
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) 
    {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }
    
    const char* Date::dateStatus()const 
    {
        return DATE_ERROR[errCode()];
    }
    
    int Date::currentYear()const 
    {
        return m_CUR_YEAR;
    }
    
    void Date::errCode(int readErrorCode) 
    {
        m_ErrorCode = readErrorCode;
    }
    
    int Date::errCode()const 
    {
        return m_ErrorCode;
    }
    
    bool Date::bad()const 
    {
        return m_ErrorCode != 0;
    }

    //v1.1 additions
    int Date::daysDiff() const
    {
        return this->daysSince0001_1_1();
    }

    Date::operator bool() const
    {
        return !this->bad();
    }

    ostream& operator<<(ostream& os, const Date& RO)
    {
        return RO.write(os);
    }

    istream& operator>>(istream& is, Date& RO)
    {
        return RO.read(is);
    }

    istream& Date::read(istream& is)
    {
        m_ErrorCode = NO_ERROR;
        char temp = '\0';
        is >> m_year;
        is >> temp;
        is >> m_mon;
        if ((int)temp >= 48 && (int)temp <= 57) //checking if character is a digit
        {
            m_mon += ((int)(temp)-48) * 10;  //ASCII to int
        }
        is >> temp;
        is >> m_day;
        if (int(temp) >= 48 && int(temp) <= 57)
        {
            m_day += ((int)(temp)-48) * 10;
        }
        if (is.fail())
        {
            m_ErrorCode = CIN_FAILED;
            is.clear();
        }
        else
        {
            this->validate();
        }
        is.clear();
        //flushKey(); removed per MS3 instructions
        return is;
    }

    ostream& Date::write(ostream& os)const
    {
        if (*this)
        {
            os << m_year << "/";
            os.fill('0');
            os.width(2);
            os << m_mon << "/";
            os.width(2);
            os << m_day;
            os.fill(' ');
        }
        else
        {
            os << dateStatus();
        }
        return os;
    }

    bool operator==(const Date& first, const Date& second)
    {
        return (first.daysDiff() == second.daysDiff());
    }

    bool operator!=(const Date& first, const Date& second)
    {
        return !(first == second);
    }

    bool operator>=(const Date& first, const Date& second)
    {
        return (first.daysDiff() >= second.daysDiff());
    }

    bool operator<=(const Date& first, const Date& second)
    {
        return (first.daysDiff() <= second.daysDiff());
    }

    bool operator<(const Date& first, const Date& second)
    {
        return (first.daysDiff() < second.daysDiff());
    }

    bool operator>(const Date& first, const Date& second)
    {
        return (first.daysDiff() > second.daysDiff());
    }

    int operator-(const Date& first, const Date& second)
    {
        return(first.daysDiff() - second.daysDiff());
    }
}
