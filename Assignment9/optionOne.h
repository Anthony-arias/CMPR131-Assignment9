// optionOne.h

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

#include <iostream>
#include <string>

using namespace std;


//PreCondition: input left position and number(lenghth) of astricks 
//PostCondition: Show the pattern of astricks and blanks 
void pattern(int left, int length)
{
	if (length == 0)
		return;
	pattern(left, length / 2);
	cout << "\t";
	for (int i = 0; i < left; i++)
		cout << "  ";
	for (int i = 0; i < length; i++)
		cout << "* ";
	cout << "\n";
	pattern(left + length / 2, length / 2);
}

#endif