/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-13

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
	MotorVehicle::MotorVehicle(const char* licenseNum, const int year)
	{
		strCpy(license, licenseNum);
		strCpy(curAddress, "Factory");
		yearMfg = year;
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(curAddress, address) != 0)
		{
			cout << "|";
			cout.width(8);
			cout << license;
			cout << "| |";
			cout.width(20);
			cout << curAddress;
			cout << " ---> ";
			cout.width(20);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << address << "|" << endl;
			cout.unsetf(ios::left);
			strCpy(curAddress, address);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		os << "| " << yearMfg << " | " << license << " | " << curAddress;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> yearMfg;
		cout << "License plate: ";
		in >> license;
		cout << "Current location: ";
		in >> curAddress;
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& vehicle)
	{
		vehicle.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, MotorVehicle& vehicle)
	{
		vehicle.read(istr);
		return istr;
	}
}