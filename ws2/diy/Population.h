/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-25

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct Population {
        char pCode[3+1];
        int people;
    };

    void sort();
    bool load(Population* city);
    bool load(const char filename[]);
    void display();
    void deallocateMemory();
}
#endif // SDDS_POPULATION_H_