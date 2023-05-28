/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-02

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Item.h"
using namespace sdds;
int main() {
   Item A;
   A.setEmpty();
   A.display();
   A.set("Hot dog buns", 4.99, false);
   A.display();
   return 0;
}


/*
Output:
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| Hot dog buns........ |    4.99 | No  |

*/