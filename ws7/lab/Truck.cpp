/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-07-13

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Truck.h"
using namespace std;
namespace sdds
{
	Truck::Truck(const char* license, int year, double newCapacity, const char* address) :MotorVehicle(license, year)
	{
		capacity = newCapacity;
		curCapacity = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		bool res = false;
		if (cargo && curCapacity!=capacity) 
		{
			if ((curCapacity + cargo) <= capacity)
			{
				curCapacity += cargo;
			}
			else
			{
				curCapacity = capacity;
			}
			res = true;
		}
		return res;
	}

	bool Truck::unloadCargo()
	{
		bool res = false;
		if (curCapacity != 0)
		{
			curCapacity = 0;
			res = true;
		}
		return res;
	}

	std::ostream& Truck::write(std::ostream& os) const
	{
		MotorVehicle::write(os);
		cout << " | " << curCapacity << "/" << capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> capacity;
		cout << "Cargo: ";
		in >> curCapacity;
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const Truck& truck)
	{
		truck.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Truck& truck)
	{
		truck.read(istr);
		return istr;
	}
}