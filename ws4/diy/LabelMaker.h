/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-09

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds
{
    class LabelMaker
    {
        int numLabels;
        Label* labels;  //dynamic array of Label objects
        void setDefault();
    public:
        LabelMaker();
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels() const;
        ~LabelMaker();
    };
}
#endif // !SDDS_LABELMAKER_H
