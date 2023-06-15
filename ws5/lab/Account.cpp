/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-14

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds 
{
	/*
	setEmpty()- used to set an Account object to any empty state
	*/
	void Account::setEmpty()
	{
		m_number = -1;
		m_balance = 0.0;
	}

	/*
	Account()- default constructor to initialize a new account
	*/
	Account::Account()
	{
		m_number = 0;
		m_balance = 0.0;
	}

	/*
	Account()- Constructor to initialize a valid account
	*/
	Account::Account(int number, double balance)
	{
		setEmpty();
		if (number >= 10000 && number <= 99999 && balance > 0)
		{
			m_number = number;
			m_balance = balance;
		}
	}

	/*
	display()- function to display account details in a specific format
	*/
	std::ostream& Account::display() const
	{
		if (*this)
		{
			cout << " ";
			cout << m_number;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		}
		else if (~*this)
		{
			cout << "  NEW  |         0.00 ";
		}
		else
		{
			cout << "  BAD  |    ACCOUNT   ";
		}
		return cout;
	}

	/*
	operator bool()- operator to check if an Account is valid
	*/
	Account::operator bool() const
	{
		return (m_number > 9999 && m_number < 99999 && m_balance >= 0) ? true : false;
	}

	/*
	operator int() - operator used to return an Account's number
	*/
	Account::operator int() const
	{
		return m_number;
	}

	/*
	operator~()- operator used to check if an account is new
	*/
	bool Account::operator~() const
	{
		return (m_number == 0) ? true : false;
	}

	/*
	operator double()- operator used to return an Account's balance
	*/
	Account::operator double() const
	{
		return m_balance;
	}

	/*
	operator=()- operator used to set a new account to a valid account number, sets Account to empty invalid state if validation fails
	*/
	Account& Account::operator=(int account)
	{
		if (~*this && account > 9999 && account < 99999) //assigning account number to a new Account
		{
			m_number = account;
		}
		else if (!bool(*this))  //preventing change to a valid account
		{
			setEmpty();
		}
		return *this;
	}

	/*
	operator=()- operator used to move a valid account into a new account
	*/
	Account& Account::operator=(Account& old)
	{
		if ( bool(old) && ~*this)
		{
			m_number = old.m_number;
			m_balance = old.m_balance;
			old.m_balance = 0;
			old.m_number = 0;
		}
		return *this;
	}

	/*
	operator+=()- operator used to add amount(deposit) to an Account 
	*/
	Account& Account::operator+=(double deposit)
	{
		if (bool(*this) && deposit > 0)
		{
			m_balance += deposit;
		}
		return *this;
	}

	/*
	operator-=()- operator used to withdraw amount(credit) from an Account
	*/
	Account& Account::operator-=(double credit)
	{
		if (bool(*this) && credit > 0 && m_balance - credit >= 0)
		{
			m_balance -= credit;
		}
		return *this;
	}

	/*
	operator>>()- operator used to move the funds from (this) Account into payee Account
	*/
	Account& Account::operator>>(Account& payee)
	{
		if (bool(*this) && bool(payee) && (m_number != payee.m_number))
		{
			payee.m_balance += m_balance;
			m_balance = 0;
		}
		return *this;
	}

	/*
	operator>>()- operator used to move the funds from depositor Account into (this) Account
	*/
	Account& Account::operator<<(Account& depositor) {
		if (bool(*this) && bool(depositor) && (m_number != depositor.m_number))
		{
			m_balance += depositor.m_balance;
			depositor.m_balance = 0;
		}
		return *this;
	}

	/*
	operator+()- helper operator that returns the sum of account numbers of first and second Accounts
	*/
	double operator+(Account& first, Account& second)
	{
		return(bool(first) && bool(second)) ? double(first) + double(second) : 0;
	}

	/*
	operator+()- helper operator that returns the sum of the value of first and account number of second Account
	*/
	double operator+=(double& first, const Account& second)
	{
		first += double(second);
		return first;
	}
}