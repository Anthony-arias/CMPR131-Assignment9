// optionFour.h


#ifndef OPTION_FOUR_LOCK
#define OPTION_FOUR_LOCK

#include <iostream>
#include <vector>
#include "input.h"

using namespace std;

void displayBoard(vector< vector <char>> v);
bool checkQueenCondition(vector< vector <char>>& v, int row, int col, int size);
bool checkWinningCondition(vector<vector <char>>& v, int size);
void autoSolve_n_Queens(vector<vector <char>>& v, int& row, int& inputColumn, int size, int& queenCount);


// Precondition: valid nested char vector to display board game, valid row, valid column, the board's size
// Postcondition: return true if queens in table is not conflicted with each other, and false if it is not
bool checkQueenCondition(vector< vector <char>>& v, int row, int col, int size)
{
	// Check columns if there are queens on the same row
	for (int i = 0; i < size; i++)
	{
		if (v[row][i] == 'Q')
		{
			return false;
		}
	}
	// Check rows if there are queens on the same column
	for (int i = 0; i < size; i++)
	{
		if (v[i][col] == 'Q')
		{
			return false;
		}
	}

	// Check diagonal lines if there are queens on the same line
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (v[i][j] == 'Q')
		{
			return false;
		}
	}

	for (int i = row, j = col; i >= 0 && j < size; i--, j++)
	{
		if (v[i][j] == 'Q')
		{
			return false;
		}
	}

	for (int i = row, j = col; i < size && j >= 0; i++, j--)
	{
		if (v[i][j] == 'Q')
		{
			return false;
		}
	}

	for (int i = row, j = col; i < size && j < size; i++, j++)
	{
		if (v[i][j] == 'Q')
		{
			return false;
		}
	}

	return true;



	/*for (int rowNumber = 1; rowNumber <= size; rowNumber++)
	{
		for (int columnNumber = 1; columnNumber <= size; columnNumber++)
		{
			if (v[rowNumber - 1][columnNumber - 1] == 'Q')
			{
				if ((rowNumber == row) || (columnNumber == col) || (rowNumber + columnNumber == (row + col)) || (rowNumber - columnNumber == (row - col)))
					return true;
			}
		}
	}
	return false;*/
}

// Precondition: valid nested char vector to display board game and the board's size
// Postcondition: return true if winning condition is valid and false if it is not
bool checkWinningCondition(vector<vector <char>>& v, int size)
{
	int findQueen = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (v[i][j] == 'Q')
				findQueen++;

	if (findQueen == size)
		return true;
	return false;
}

// Precondition: valid nested char vector to display board game
// Postcondition: display the content in board game
void displayBoard(vector< vector <char>> v)
{
	cout << endl;
	int shapeSize = v.capacity() + 2;
	for (int row = 0; row < shapeSize; ++row)
	{
		cout << "\t";
		if (row == 0 || row == shapeSize - 1)
		{
			for (int column = 0; column < shapeSize; ++column)
			{
				if (row == 0)
				{
					if (column == 0)
						cout << char(201);
					else
					{
						if (column == shapeSize - 1)
							cout << char(205) << char(187);
						else
							cout << string(2, char(205));
					}
				}
				else
				{
					if (column == 0)
						cout << char(200);
					else
					{
						if (column == shapeSize - 1)
							cout << char(205) << char(188);
						else
							cout << string(2, char(205));
					}
				}
			}
		}

		else
		{
			for (int column = 0; column < shapeSize; ++column)
				if (column == 0)
					cout << char(186) << " ";
				else
				{
					if (column == shapeSize - 1)
						cout << " " << char(186);
					else
					{
						int i = row - 1;
						int j = column - 1;
						if (v[i][j] == '_' || v[i][j] == 'Q')
						{
							if (i == v.capacity() - 1 && v[i][j] == '_')
							{
								if (j < v.capacity() - 1)
									cout << ' ' << char(179);
								else
									cout << ' ';
							}
							else
							{
								if (j < v.capacity() - 1)
									cout << v[i][j] << char(179);
								else
									cout << v[i][j];
							}
						}
					}
				}
		}
		cout << endl;
	}
}


void autoSolve_n_Queens(vector<vector <char>>& v, int& row, int& inputColumn, int size, int& queenCount)
{
	if (size == 1) // case n = 1, then return true 
	{
		queenCount++;
		v[row - 1][inputColumn - 1] = 'Q';
		displayBoard(v);
	}

	if (queenCount == size && row == size) // if the solution is existed 
		displayBoard(v);

	if (inputColumn >= size) // col is equals to size - 1, then make inputColumn = 1 and increase row to row + 1;
	{
		inputColumn = 1;
		++row;
	}

	if (checkQueenCondition(v, row, inputColumn, size) && (inputColumn < size))
	{
		if (inputColumn < size) // the exist row is 1, and col is increasing until it equals to size - 1
		{
			v[row - 1][inputColumn - 1] = 'Q';
			queenCount++;
			displayBoard(v);
		}
	}

	autoSolve_n_Queens(v, row, ++inputColumn, size, queenCount);

}

#endif