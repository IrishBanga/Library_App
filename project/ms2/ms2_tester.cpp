/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 2
Module: ms2_tester
Filename: ms2_tester.cpp
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date        Reason
2023/06/27  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/
// Final Project Milestone 2
// LibApp Mockup Module
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "LibApp.h"
using namespace std;
int main() {
   sdds::LibApp theApp;
   cout << endl << "Testing exiting with no change:" << endl;
   theApp.run();
   cout << endl << "Testing exiting with change and discarding data:" << endl;
   theApp.run();
   cout << endl << "Testing exiting with change and saving data:" << endl;
   theApp.run();
   cout << endl << "Testing all actions:" << endl;
   theApp.run();
   return 0;
}
/* data to be entered:
 1- 1
 2- 0
 3- 0
 4- 2
 5- 1
 6- 0
 7- 0
 8- 1
 9- 3
10- 1
11- 0
12- 1
13- 4
14- 0
15- 2
16- 0
17- 1
*/