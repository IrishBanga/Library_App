/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-13

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"
namespace sdds
{
	class Truck:public MotorVehicle
	{
		double capacity{};
		double curCapacity{};
	public:
		Truck(const char* license, int year, double newCapacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const Truck& text);
	std::istream& operator>>(std::istream& istr, Truck& text);
}

#endif // !SDDS_TRUCK_H

