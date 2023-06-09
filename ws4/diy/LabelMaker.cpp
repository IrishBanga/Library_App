/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-09

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "LabelMaker.h"
using namespace std;

namespace sdds 
{
    /*
    LabelMaker()- constructor for initialising a LabelMaker with default values(safe state)
    */
    LabelMaker::LabelMaker()
    {
        setDefault();
    }

    /*
    LabelMaker()- creates a dynamic array of Labels to the size of noOfLabels
    */
    LabelMaker::LabelMaker(int noOfLabels) 
    {
        if (noOfLabels > 0) 
        {
            numLabels = noOfLabels;
            labels = new Label[numLabels];
        }
        else 
        {
            setDefault();
        }
    }

    /*
    setDefault()- sets LabelMaker to default(empty state)
    */
    void LabelMaker::setDefault()
    {
        numLabels = 0;
        labels = nullptr;
    }

    /*
    ~LabelMaker()- deallocates the memory when LabelMaker goes out of scope
    */
    LabelMaker::~LabelMaker()
    {
       delete[] labels;
       labels = nullptr;
    }

    /*
    readLabels()- gets the contents of the Labels from user with help of Label::readLabel()
    */
    void LabelMaker::readLabels() 
    {
        cout << "Enter " << numLabels << " labels:" << endl;
        for (int i = 0; i < numLabels; i++) 
        {
            cout << "Enter label number " << i + 1 << endl;
            cout << "> ";
            labels[i].readLabel();
        }
    }

    /*
    printLables()- Prints the Labels from the array of Label objects using Label::printLabel()
    */
    void LabelMaker::printLabels() const 
    {
        for (int i = 0; i < numLabels; i++) 
        {
            
            labels[i].printLabel();
            cout << endl;
        }
    }
}
