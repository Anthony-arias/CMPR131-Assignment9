#pragma once

#include <iostream>
using namespace std;

class nQueens
{
private:
	int size;
	char** board;
	int queenCount;
	bool solutionExists;

public:

	// Argument constructor
	nQueens(const int& newSize)
	{
		size = newSize;
		board = new char*[size];
		queenCount = 0;
		solutionExists = true;

		for (int i = 1; i <= size; i++)
			board[i - 1] = new char[size];

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				board[i - 1][j - 1] = char(95);	
	}

	// Destructor
	~nQueens()
	{
		for (int i = 1; i <= size; i++)
			delete[] board[i - 1];
		delete[] board;
	}

	// Precondition(s): The place must not have an existing queen nor be attacked by a queen
	// Postcondition(s): Sets the queen at the row and column location
	void inputQueen(int& row, int& column)
	{
		board[row - 1][column - 1] = 'Q';
		queenCount++;
	}

	// Precondition(s): The place must have an existing queen
	// Postcondition(s): Removes the queen at the row and column location
	void removeQueen(int& row, int& column)
	{
		board[row - 1][column - 1] = char(95);
		queenCount--;
	}

	// Precondition(s): None
	// Postcondition(s): Prints the game solution with borders and objects
	void showSolution() 
	{
		if (size <= 0)
			return;

		if (no_solution_cases() || !solutionExists)
		{
			cout << "\n\t" << "No solutions." << endl;
			return;
		}

		cout << "\n\t" << size << "-Queens solution" << endl;
		displayBoard();
		cout << endl;
	}

	// Precondition(s): NA
	// Postcondition(s): Display the board game
	void displayBoard() 
	{
		// Print top border
		cout << "\t" << char(201);
		for (int currentSpace = 1; currentSpace <= (2 * size - 1); ++currentSpace)
			cout << char(205);
		cout << char(187) << endl;

		// Print rows 
		for (int i = 1; i <= size; i++)
		{
			cout << "\t" << char(186);
			for (int j = 1; j <= size; j++)
			{
				if (board[i - 1][j - 1] != 'Q' && (size == 1 || i == size))	//No underline for last row
					cout << " ";
				else
					cout << board[i - 1][j - 1];

				if (j == size)
					cout << char(186) << endl;
				else
					cout << char(179);
			}
		}

		// Print bottom border
		cout << "\t" << char(200);
		for (int currentSpace = 1; currentSpace <= (2 * size - 1); currentSpace++)
			cout << char(205);
		cout << char(188) << endl;
			
	}

	// Precondition(s): row and column exist on the board
	// Postcondition(s): Returns true if the location is conflicted by a queen
	bool checkQueenCondition(int& row, int& column) 
	{
		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)
			{
				if (board[i - 1][j - 1] == 'Q')
				{
					if ((i == row) || (j == column) || (i + j == (row + column)) || (i - j == (row - column)))
						return true;
				}
			}
		}
		return false;
	}

	// Precondition(s): NA
	// Postcondition(s): Returns true when size = 2 or size = 3
	bool no_solution_cases() 
	{
		if (size == 2 || size == 3)
			return true;
		return false;
	}

	// Precondition(s): Size is not 2 or 3
	// Postcondition(s): Show one possible solution to nQueen game
	bool auto_solve()
	{
		if (no_solution_cases())	//No solutions exist for 2x2 or 3x3 board
			return false;

		int currentRow = find_rowWithoutQueen();
		solutionExists = auto_inputQueen(currentRow);
	}

	// Precondition(s): row is positve and game is not solved yet
	// Postcondition(s): Sets a queen on the row at the non-conflicted location
	bool auto_inputQueen(int& row)
	{
		if (queenCount == size)
			return true;

		bool newQueenSet = false;
		for (int column = 1; column <= size; column++)
		{
			if (board[row - 1][column - 1] != 'Q' && !checkQueenCondition(row, column))
			{			
				inputQueen(row, column);
				newQueenSet = true;
				break;
			}
		}

		if (!newQueenSet)
			if (!auto_moveQueen(--row))
				return false;

		auto_inputQueen(++row);
	}

	// Precondition(s): row is positve
	// Postcondition(s): Moves the queen on the row to the next non-conflicted location
	bool auto_moveQueen(int& row)
	{
		bool queenShifted = false;
		bool queenRemoved = false;
		for (int column = 1; column <= size; column++)
		{
			if (board[row - 1][column - 1] == 'Q')
			{
				removeQueen(row, column);
				queenRemoved = true;
				continue;
			}

			if (queenRemoved)
				if (!checkQueenCondition(row, column))
				{
					inputQueen(row, column);
					queenShifted = true;
					return true;
				}
		}

		if (!queenShifted)
			auto_moveQueen(--row);
	}

	// Precondition(s): NA
	// Postcondition(s): Finds the smallest row that does not have a queen yet
	int find_rowWithoutQueen()
	{
		for (int row = 1; row <= size; row++)
		{
			bool queenExists = false;
			for (int column = 1; column <= size; column++)
				if (board[row - 1][column - 1] == 'Q')
				{
					queenExists = true;
					break;
				}

			if (!queenExists)
				return row;
		}

		return 0;
	}
};
