// optionThree.h

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK


#include <iostream>
#include "input.h"
#include <vector>
#include "Tower.h"

using namespace std;



// Precondition: intput tree towers and number of rings
// Postcondition: display the content of three towers
void display(Tower* peg, int numberOfRings)
{
	vector<int>dataA;
	vector<int>dataB;
	vector<int>dataC;
	dataA = peg[0].getAllValues(numberOfRings);
	dataB = peg[1].getAllValues(numberOfRings);
	dataC = peg[2].getAllValues(numberOfRings);
	sort(dataA.begin(), dataA.end());
	sort(dataB.begin(), dataB.end());
	sort(dataC.begin(), dataC.end());

	string* graphic = new string[numberOfRings + 1];
	for (int i = 0; i <= numberOfRings; i++)
	{
		if (i == 0)
			graphic[0] = string(numberOfRings, char(32)) + string(1, char(186)) + string(numberOfRings, char(32));
		else
			graphic[i] = string(numberOfRings - i, char(32)) + string(i, char(254)) + to_string(i) + string(i, char(254)) + string(numberOfRings - i, char(32));
	}
	string* noGraphic = new string[numberOfRings + 1];
	noGraphic[0] = string(5, char(32)) + string(1, char(186)) + string(5, char(32));
	for (int index = 1; index <= numberOfRings; index++)
		noGraphic[index] = string(5, char(32)) + to_string(index) + string(5, char(32));

	if (numberOfRings > 9)
	{

		
		cout << "\n\t\t" << noGraphic[0] << "\t" << noGraphic[0] << "\t" << noGraphic[0] << endl;
		for (int i = 0; i < numberOfRings; i++)
			cout << "\t\t" << noGraphic[dataA[i]] << "\t" << noGraphic[dataB[i]] << "\t" << noGraphic[dataC[i]] << endl;
		cout << "\t\t" << string(5, char(205)) + string(1, char(202)) + string(5, char(205)) << "\t"
			<< string(5, char(205)) + string(1, char(202)) + string(5, char(205)) << "\t" << string(5, char(205)) + string(1, char(202)) + string(5, char(205)) << endl;
		cout << "\t\t" << string(5, char(32)) + "A" + string(5, char(32)) << "\t" << string(5, char(32)) + "B" + string(5, char(32))
			<< "\t" << string(5, char(32)) + "C" + string(5, char(32)) << endl;

	}
	else
	{
		
		cout << "\n\t\t" << graphic[0] << "\t" << graphic[0] << "\t" << graphic[0] << endl;
		for (int i = 0; i < numberOfRings; i++)
			cout << "\t\t" << graphic[dataA[i]] << "\t" << graphic[dataB[i]] << "\t" << graphic[dataC[i]] << endl;
		cout << "\t\t" << string(numberOfRings, char(205)) + string(1, char(202)) + string(numberOfRings, char(205)) << "\t"
			<< string(numberOfRings, char(205)) + string(1, char(202)) + string(numberOfRings, char(205)) << "\t" << string(numberOfRings, char(205)) + string(1, char(202)) + string(numberOfRings, char(205)) << endl;
		cout << "\t\t" << string(numberOfRings, char(32)) + "A" + string(numberOfRings, char(32)) << "\t" << string(numberOfRings, char(32)) + "B" + string(numberOfRings, char(32))
			<< "\t" << string(numberOfRings, char(32)) + "C" + string(numberOfRings, char(32)) << endl;
	}
	// Free the memory.
	delete[] graphic;
	graphic = nullptr;
	delete[] noGraphic;
	noGraphic = nullptr;

}

void towerOfHanoi(int n, int numberOfRings, Tower *peg, int from_peg, int to_peg, int aux_peg, int& count)
{
	int disk;
	char pegName[3] = { 'A','B','C' };
	if (n == 1)
	{
		count++;
		peg[from_peg-1].pop(disk);
		peg[to_peg - 1].push(disk);
		cout << "\n\tMove#" << count << ": disk 1 from peg-" << pegName[from_peg - 1] << " to peg-" << pegName[to_peg - 1] << "..." << endl;
		display(peg, numberOfRings);
		return;
	}
	else
	{
		towerOfHanoi(n - 1, numberOfRings, peg, from_peg, aux_peg, to_peg, count);
		count++;
		peg[from_peg-1].pop(disk);
		peg[to_peg - 1].push(disk);
		cout << "\n\tMove#" << count << ": disk " << n << " from peg-" << pegName[from_peg - 1] << " to peg-" << pegName[to_peg - 1] << "..." << endl;
		display(peg, numberOfRings);
		towerOfHanoi(n - 1, numberOfRings, peg, aux_peg, to_peg, from_peg, count);
	}

}



#endif