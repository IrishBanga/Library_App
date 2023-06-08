/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-08

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#define PI (3.14159265)
using namespace std;

namespace sdds 
{
    /*
    Canister()- constructor for initialising a Canister object with default values
    */
    Canister::Canister() 
    {
        setToDefault();
    }

    /*
    Canister()- a constructor that names a Canister with default values
    */
    Canister::Canister(const char* contentName)
    {
        setToDefault();
        setName(contentName);
        m_height = 13.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    /*
    Canister()- a constructor that sets the name and dimensions for the Canister, and the default values
    */
    Canister::Canister(double height, double diameter, const char* contentName) 
    {
        setToDefault();
        if (height>=10 &&height<=40 && diameter>=10 && diameter<=30)
        {
            setName(contentName);
            m_diameter = diameter;
            m_height = height;
            m_contentVolume = 0;
            m_usable = true;
        }
        else
        {
            m_usable = false;
        }
    }

    /*
    ~Canister()- desctructor uses clear() that deallocates dynamic memory and resets a Canister to default except dimensions 
    */
    Canister::~Canister() 
    {
        clear();
    }

    /*
    setToDefault()- sets the Canister attributes to their default values
    */
    void Canister::setToDefault() 
    {
        m_contentName = NULL;
        m_diameter = 10;
        m_height = 13;
        m_contentVolume = 0;
        m_usable = true;
    }

    /*
    setName()- sets the content name of the current Canister
    */
    void Canister::setName(const char* Cstr) 
    {
        clear();
        if (Cstr != NULL && m_usable==true)
        {
            m_contentName = NULL;
            m_contentName = new char[strLen(Cstr) + 1]; //allocating dynamic memory for Canister name
            strCpy(m_contentName, Cstr);
        }
    }

    /*
    isEmpty()- returns true if the content volume is less than 0.00001 CCs 
    */
    bool Canister::isEmpty()const 
    {
        return (m_contentVolume < 0.00001) ? true : false;
    }

    /*
    hasSameContent()- compares the content names of this Canister with the one from argument
    */
    bool Canister::hasSameContent(const Canister& C)const
    {
        bool res = false;
        if (m_contentName != NULL && C.m_contentName != NULL)
        {
            res = (strCmp(m_contentName, C.m_contentName) == 0) ? true : false;
        }
        else
        {
            res = false;
        }
        return res;
    }
    
    /*
    setContent()- sets the content name of a canister 
    */
    Canister& Canister::setContent(const char* contentName)
    {
        if (contentName == NULL) {
            m_usable = false;
        }
        else if(m_contentVolume==0.0)
        {
            setName(contentName);
        }
        else if (strCmp(m_contentName,contentName)!=0)
        {
            m_usable = false;
        }
        return *this;
    }

    /*
    pour()- adds quantity to m_contentVolume if it fits otherwise renders it unusable
    */
    Canister& Canister::pour(double quantity) 
    {
        if(volume() +quantity <= capacity())
        {
            m_contentVolume += quantity;
        }
        else
        {
            m_usable = false;
        }
        return *this;
    }

    /*
    pour()- adds the max possible quantity from Canister(Can) into current(this) Canister, 
    renders 'this' Canister unusable if contents differ
    */
    Canister& Canister::pour(Canister& Can) 
    {
        if (!hasSameContent(Can)) //setting the m_usable flag to false in case the contents are not same
        {
            m_usable = false;
        }
        setContent(Can.m_contentName);
        double avlbl = capacity() - volume(); //determining available space in 'this' Canister
        if (avlbl < Can.volume())
        {
            m_contentVolume = capacity();
            Can.m_contentVolume -= avlbl;
        }
        else
        {
            pour(Can.volume());
            Can.m_contentVolume = 0;
        }
        
        return *this;
    }

    /*
    volume()- returns the volume of contents in a Canister
    */
    double Canister::volume()const 
    {
        return m_contentVolume;
    }

    /*
    display()- displays Canister contents in a specific format
    */
    std::ostream& Canister::display()const
    {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
         cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (m_usable==false) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != NULL) {
            cout << " of ";
            cout.width(7);
            cout<< volume() << "cc   " << m_contentName;
        }
        return cout;
    }

    /*
    capacity()- calculates and returns the capacity of a Canister
    */
    double Canister::capacity()const 
    {
        return PI*(m_height - 0.267)*(m_diameter / 2)*(m_diameter / 2);
    }

    /*
    clear()- deallocates dynamic memory and resets a Canister to default except dimensions
    */
    void Canister::clear() 
    {
        delete[] m_contentName;
        m_contentName = NULL;
        m_contentVolume = 0;
        m_usable = true;
    }
}