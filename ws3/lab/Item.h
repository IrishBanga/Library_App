/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-28

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#define TAX_PERCENT (0.13) // macro definition for the tax percentage

namespace sdds {
   class Item {
      char m_itemName[21];  // holds the item name up to 20 chars
      double m_price; 
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
