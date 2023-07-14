/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 2
Module: Date
Filename: Date.h
Version 1.1
Author: Fardad Soleimanloo, Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/06/27  Preliminary release (Author: Fardad Soleimanloo)
2023/07/08  Added declarations for operator overlaods and 
            helper, read, write functions (Author: Irish Banga)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
namespace sdds 
{
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"
    };
    const int  MIN_YEAR = 1500;
    class Date {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1
        bool validate();             /* validates the date setting the error code and then returning the result
                                      true, if valid, and false if invalid.*/
        void errCode(int);           // sets the error code
        int systemYear()const;       // returns the current system year
        bool bad()const;             // return true if
        int mdays()const;            // returns the number of days in current month
        void setToToday();           // sets the date to the current date (system date)
    public:
        Date();                      // creates a date with current date
        Date(int year, int mon, int day); /* create a date with assigned values
                                           then validates the date and sets the
                                           error code accordingly */
        int errCode()const;         // returns the error code or zero if date is valid
        const char* dateStatus()const;  // returns a string corresponding the current status of the date
        int currentYear()const;         // returns the m_CUR_YEAR value;

        //v1.1 additions
        int daysDiff() const;
        operator bool() const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout)const;
    };

    //v1.1 additions
    bool operator==(const Date& first, const Date& second);
    bool operator!=(const Date& first, const Date& second);
    bool operator>=(const Date& first, const Date& second);
    bool operator<=(const Date& first, const Date& second);
    bool operator<(const Date& first, const Date& second);
    bool operator>(const Date& first, const Date& second);
    int operator-(const Date& first, const Date& second);
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);
}
#endif // !SDDS_DATE_H



