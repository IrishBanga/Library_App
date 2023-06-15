/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-14

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator int() const;
      operator double() const;
      operator bool() const;
      bool operator~() const;
      Account& operator=(int newAccountNum);
      Account& operator=(Account& original);
      Account& operator+=(double deposit);
      Account& operator-=(double withdrawal);
      Account& operator>>(Account& payee);
      Account& operator<<(Account& depositor);
   };
   double operator+(Account&,Account&);
   double operator+=(double&,const Account&);
}
#endif // SDDS_ACCOUNT_H_