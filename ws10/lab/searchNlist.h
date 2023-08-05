/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-08-05

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"
namespace sdds 
{
    /// <summary>
    /// This template function performs a search operation on an array of objects of type T using a search parameter of type KEY.
    /// It makes use of other templates (i.e. add() template from Collection class) to store search results (in a Collection of objects of type T)
    /// ASSUMPTIONS: 
    /// operator== is defined for Type T objects
    /// "typeAddress" argument is a valid  reference to a Collection object of type T
    /// "arr[]" has valid objects present in it
    /// "size" is positive and correctly identifies the number of valid elements in the array
    /// "search" has valid data passed to it (i.e, relevant to the operator== logic of type T)
    /// </summary>
    /// <typeparam name="KEY">the type of search parameter; allows flexibilty with search operations</typeparam>
    /// <typeparam name="T">is the type of objects on which the search operation is being called</typeparam>
    /// <param name="typeAddress">address of Collection of objects in which the objects matching "search" will be stored</param>
    /// <param name="arr">array of objects of type T to be searched</param>
    /// <param name="size">size of the array</param>
    /// <param name="search">the parameter based on which search is to be conducted</param>
    /// <returns>
    /// Returns a boolean value indicating whether the search parameter was found in the array or not.
    /// If the search parameter is found, the matching objects will be added to the Collection passed in "typeAddress."
    /// The return value is true if at least one match is found, otherwise false.
    /// </returns>
    template <typename T, typename KEY>
    bool search(Collection<T>& typeAddress, T arr[], int size, KEY search)
    {
        bool match = false;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == search)
            {
                match = true;
                typeAddress.add(arr[i]);
            }
        }
        return match;
    }

    /// <summary>
    /// Displays the elements of an array of type T along with a specified title.
    /// ASSUMPTIONS:
    /// "title" is not empty or nullptr
    /// Insertion operator is overloaded for type T object
    /// "arr[]" has valid objects present in it
    /// "size" is positive and correctly identifies the number of valid elements in the array
    /// </summary>
    /// <typeparam name="T">the type of object on which listArrayElements is being called</typeparam>
    /// <param name="title">the title to be printed before displaying the elements</param>
    /// <param name="arr">array of type T containing valid elements</param>
    /// <param name="size">size of the array</param>
    template <typename T>
    void listArrayElements(const char* title, T arr[], int size)
    {
        std::cout << title << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << i + 1 << ": " << arr[i] << std::endl;
        }
    }
}

#endif // !SDDS_SEARCHNLIST_H