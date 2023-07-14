/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-13

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>
namespace sdds
{
	class MotorVehicle 
	{
		char license[9]{};
		char curAddress[64]{};
		int yearMfg{};
	public:
		MotorVehicle(const char* licenseNum, const int yearMfg);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& text);
	std::istream& operator>>(std::istream& istr, MotorVehicle& text);
}

#endif // !SDDS_MOTORVEHICLE_H
