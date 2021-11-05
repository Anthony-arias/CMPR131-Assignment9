// optionTwo.h

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK

#include <iostream>
#include "input.h"
#include <vector>
#include "Tower.h"

using namespace std;

//PreCondition: input low, high and guessCount
//PostCondition: Guess a number
int guess(int low, int high, int &guessCount)
{
	char choice;
	int midPoint;
	if (low == high)
	{
		guessCount++;
		cout << "\n\tYour number must be " << high << '.' << endl;
	}
	else if (low < high)
	{
		guessCount++;
		midPoint = (low + high) / 2;
		choice = inputChar("\n\tIs your number " + to_string(midPoint) + "? (Y-yes or N-no) ", 'Y', 'N');
		while (toupper(choice) == 'N')
		{
			choice = inputChar("\n\tIs your number larger than " + to_string(midPoint) + "? (Y-yes or N-no) ", 'Y', 'N');
			if (toupper(choice) == 'Y')
				return guess(midPoint + 1, high, guessCount);
			else
				return guess(low, midPoint - 1, guessCount);
		}
	}

	cout << "\n\tNumber of guesses: "<< guessCount << endl;
}
#endif