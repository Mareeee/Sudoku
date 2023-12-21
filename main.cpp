#include <iostream>
#include "Game.hpp"
#include "Sudoku.hpp"
using namespace std;

int main() {
	string filepath = "Sudoku.txt";
	Game sudoku(filepath);
	cout << "      *****************************" << endl;
	cout << "      *  WELCOME TO SUDOKUSPHERE! *" << endl;
	cout << "      *****************************" << endl;
	bool izlaz = false;
	while (!izlaz) {
		cout << "\n[1] - Solve Sudoku" << endl;
		cout << "[2] - Generate Sudoku" << endl;
		cout << "[3] - Print Stats" << endl;
		cout << "[4] - Print Sudoku" << endl;
		cout << "[X] - Exit" << endl;
		cout << "\nEnter your choice: ";
		char input;
		cin >> input;
		switch (input)
		{
		case '1' : sudoku.solveSudoku();
			break;
		case '2': sudoku.generateSudoku(69);
			break;
		case '3': sudoku.printStats();
			break;
		case '4': sudoku.printSudoku();
			break;
		case 'x':;
		case 'X': izlaz = true;
			break;
		default:
			system("CLS");
			cout << "Invalid Input!\n" << endl;
			break;
		}
	}
}