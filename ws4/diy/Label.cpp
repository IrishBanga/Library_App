/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-06-09

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Label.h"
#include "cstring.h"
#define MAX_LEN 70  //defining size for maximum size allowed for frame content
using namespace std;

namespace sdds
{
	/*
	Label()- constructor for initialising a Label object with default values
	*/
	Label::Label() 
	{
		setToDefault();
	}

	/*
	Label()- constructor that defines a Label object with default values and a frame
	*/
	Label::Label(const char* frameArg)
	{
		setToDefault();
		setFrame(frameArg);
	}

	/*
	Label()- constructor that defines a Label object with a frame and the content
	*/
	Label::Label(const char* frameArg, const char* frameContent)
	{
		setToDefault();
		setFrame(frameArg);
		content = new char[(strLen(frameContent) <= MAX_LEN) ? strLen(frameContent) + 1 : MAX_LEN + 1];
		strnCpy(content, frameContent, (strLen(frameContent) <= MAX_LEN) ? strLen(frameContent) : MAX_LEN);
	}

	/*
	~Canister()- desctructor uses clear() function which deallocates dynamic memory
	*/
	Label::~Label()
	{
		clear();
	}

	/*
	setToDefault()- sets the Label attributes to default values
	*/
	void Label::setToDefault()
	{
		strCpy(frame, "+-+|+-+|");
		content = nullptr;
	}

	/*
	clear()- deallocates dynamic memory alloted for Frame content storage
	*/
	void Label::clear()
	{
		delete[] content;
		content = nullptr;
	}

	/*
	setFrame()- sets the frame schema as provided by the (str) argument
	*/
	void Label::setFrame(const char* str)
	{
		strCpy(frame, str);
	}

	/*
	readLabel()- reads label from console up to 70 characters and stores it in Label content
	*/
	void Label::readLabel()
	{
		char label[MAX_LEN + 1];
		scanf("%70[^\n]", label);  //getting a console input of maximum 70 characters
		label[MAX_LEN] = '\0';
		while (getchar() != '\n');  //flushing the input buffer to prevent any errors in following steps
		clear();
		content = new char[(strLen(label) <= MAX_LEN) ? strLen(label) + 1 : MAX_LEN + 1];  //allocating dynamic memory based on length of console input
		strnCpy(content, label, (strLen(label) <= MAX_LEN) ? strLen(label) : MAX_LEN);
	}

	/*
	printLabel()- prints the label by drawing the frame around the content (uses custom, self-developed functions- pattern() and line())
	*/
	ostream& Label::printLabel() const
	{
		if (content != NULL)
		{
			pattern(frame[0], frame[1], frame[2], frame[3], frame[4], frame[5], frame[6], frame[7], ' ', content, (int)strLen(content) + 4, 5);
		}
		return cout;
	}

	/*
	pattern()- custom function developed to break label into individual lines and display them using line() function  
	*/
	void Label::pattern(char leftTop, char top, char topRight, char right, char rightBottom, char bottom, char bottomLeft, char left, char fill, char* content, int width, int height) const
	{
		line(leftTop, top, topRight, width);
		cout << endl;
		line(left, fill, right, width);
		cout << endl;
		cout << left << " " << content << " " << right << endl;
		line(left, fill, right, width);
		cout << endl;
		line(bottomLeft, bottom, rightBottom, width);
	}

	/*
	line()- custom function printing a single formatted line based on the function arguments provided
	*/
	void Label::line(char left, char fill, char right, int length) const
	{
		int i = 0;
		cout << left;
		while (i < (length - 2))
		{
			cout << fill;
			i++;
		}
		cout << right;
	}
}
