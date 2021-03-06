// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 9:
// 11/04/2021


#include <iostream>
#include <string>
#include "optionOne.h"
#include "optionTwo.h"
#include "optionThree.h"
#include "nQueens.h"
#include "input.h"

void displayMainMenu(void);
void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);
void programFour(void);

using namespace std;

int main(void)
{
    mainMenu();
    return 0;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ", 0, 4);
        switch (userInput)
        {
        case 0: return;
        case 1: programOne(); break;
        case 2: programTwo(); break;
        case 3: programThree(); break;
        case 4: programFour(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..3." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: Show the pattern of astricks and blanks
void programOne(void)
{
	do
	{
		clearScreen();
		cout << "\t1> Pattern of astricks and blanks" << endl;
		cout << "\t" + string(100, char(196)) << endl;
		int n = inputInteger("\n\tEnter a positive number of astricks: ", true);
		cout << endl;
		pattern(0, n);
	} while (isRepeat("\tPlay again? (Y-yes or N-no)? "));
}


//PreCondition: NA
//PostCondition: Guessing player's number
void programTwo(void)
{
    do
    {
        clearScreen();
        srand(time(0));
        int number = rand()% 1000;
        int guessCount = 0;
        cout << "\t2> Guess your number between 1 to " << number << "." << endl;
        cout << "\n\tThink of a number from 1 to " << number << "." << endl;
        pause("\n\tPress Enter to begin...");
        guess(1, number, guessCount);
        cout << endl;
    } while (isRepeat("\tPlay again? (Y-yes or N-no)? "));
}

//PreCondition: NA
//PostCondition: Solving tower of Hanoi problem use recursive
void programThree(void)
{
    do
    {
        clearScreen();
        cout << "\t3> Tower of Hanoi (Recursive)" << endl;
        cout << "\t" + string(100, char(196)) << endl;
        int numberOfRings = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, 64);
        if (numberOfRings >= 10)
            cout << "\n\tNote: The rings will be represented with numbers (1 is the smallest size and " << numberOfRings << " is the largest size)." << endl;
        int count = 0;
        Tower peg[3];
        for (int i = numberOfRings; i >= 1; i--)
            peg[0].push(i);
        display(peg, numberOfRings);
        towerOfHanoi(numberOfRings, numberOfRings, peg, 1, 3, 2, count);
        if (count == 1)
            cout << "\n\tThe computer has solved the game in " << count << " move." << endl;
        else
            cout << "\n\tThe computer has solved the game in " << count << " moves." << endl;
    } while (isRepeat("\tPlay again? (Y-yes or N-no)? "));
}

//PreCondition: NA
//PostCondition: Solving n-Queens problem use recursive
void programFour(void)
{
    clearScreen();
    cout << "\t4> Solve n-Queens (Recursive)" << endl;
    cout << "\t" + string(100, char(196)) << endl;

    int queenCount = 0;
    int row = 1;
    int n = inputInteger("\n\tEnter the board dimension nxn (1..12): ", 1, 12);
    int inputColumn = inputInteger("\n\tEnter the column position (1.." + to_string(n) + ") of the first Queen on row 1: ", 1, n);
    if (n == 2 || n == 3)
    {
        cout << "\tNo solution.\n\n";
        system("PAUSE");
    }
    else if (n == 4 && inputColumn == 1 || n == 4 && inputColumn == 4)
    {
        cout << "\tNo solution.\n\n";
        system("PAUSE");
    }

    else
    {
        nQueens board(n);
        board.inputQueen(row, inputColumn);
        board.auto_solve();
        board.showSolution();
        cout << "\n\n";
        system("PAUSE");
    }
}


//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 9: Recursive Applications by Anthony, An, Van, Vincent, Nhan (11/04/21)" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\t1> Pattern of astricks and blanks" << endl;
    cout << "\t\t2> Guess a number" << endl;
    cout << "\t\t3> Solve Tower of Hanoi" << endl;
    cout << "\t\t4> Solve n-Queens" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}