// optionTwo.h

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK

#include <iostream>
#include "input.h"
#include <vector>
#include "Tower.h"

using namespace std;

int guess(int low, int high, int &guessCount)
{
	char choice;
	int midPoint;
	if (low == high)
	{
		guessCount++;
		cout << "\n\tYour number must be " << high << endl;
	}
	else if (low < high)
	{
		guessCount++;
		midPoint = (low + high) / 2;
		cout << "\n\tIs your number " << midPoint << "? (Y-yes or N-no) ";
		cin >> choice;
		while (choice == 'n')
		{
			cout << "\n\tIs your number larger then " << midPoint << "? ";
			cin >> choice;
			if (choice == 'y')
				return guess(midPoint + 1, high, guessCount);
			else
				return guess(low, midPoint - 1, guessCount);
		}
	}

	cout << "\n\tNumber of guesses: "<< guessCount << endl;
}
#endif