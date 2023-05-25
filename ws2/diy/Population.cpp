/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-25

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h" 
#include "Population.h"
#include "File.h"
using namespace std;

namespace sdds 
{
    int noOfCities;
    Population* city;
    void sort() {
        int i, j;
        Population temp;
        for (i = noOfCities - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (city[j].people > city[j + 1].people) {
                    temp = city[j];
                    city[j] = city[j + 1];
                    city[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population* city)
    {
        bool ok = false;
        if (read(city->pCode) && read(city->people))
        {
            ok = true;
        }
        return ok;
    }

    bool load(const char file[]) {
        bool ok = false;
        if (openFile(file))
        {
            noOfCities = noOfRecords();
            city = new Population[noOfCities];
            int reads = 0;
            for (int i = 0; i < noOfCities; i++)
            {
                reads += load(&city[i]);
            }
            if (reads != noOfCities)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
                closeFile();
            }
        }
        else {
            cout << "Could not open data file: " << file << endl;
        }
        return ok;
    }

    void display()
    {
        sort();
        cout << "Postal Code: population\n"
                "-------------------------" << endl;
        int total = 0;
        for (int i = 0; i < noOfCities; i++)
        {
            cout << i + 1 << "- " << city[i].pCode << ":  " << city[i].people << endl;
            total += city[i].people;
        }
        cout<< "-------------------------\nPopulation of Canada: "<<total <<endl;
    }

    void deallocateMemory()
    {
        delete[] city;
        city = nullptr;
    }


}