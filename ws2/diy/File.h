/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-05-25

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	
	bool read(char str[]);
	bool read(int &population);
}
#endif // !SDDS_FILE_H


