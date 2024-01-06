/**
 * @brief Represents the Sudoku game and provides game-related functionalities.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include "Game.hpp"

Game::Game(string sudokuFilepath, string configFilepath) : fileHandler(sudokuFilepath, configFilepath), sudoku(fileHandler.loadSudoku()), gamesPlayed(fileHandler.loadConfig()) {}

void Game::resetSudoku() {
	cout << "\n      ******************" << endl;
	cout << "      *  SUDOKU RESET! *" << endl;
	cout << "      ******************" << endl;
	fileHandler.save(sudoku, gamesPlayed);
}

void Game::solveSudoku() {
	sudoku.solve();
	fileHandler.save(sudoku, gamesPlayed);
	cout << sudoku;
}

void Game::resetConfig() {
	cout << "Are you sure that you wish to reset the game counter? Y/N: ";
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y') {
		fileHandler.clearConfig();
		gamesPlayed = 0;
		cout << "\nGame counter successfully reset!" << endl;
	}
}

void Game::generateSudoku(int numToRemove) {
	if (sudoku.isFilled()) {
		++gamesPlayed;
	}
	sudoku = generateRandomSudoku(numToRemove);
	fileHandler.save(sudoku, gamesPlayed);
	cout << sudoku;
}

void Game::printStats() {
	Sudoku9 checkSudoku = fileHandler.loadSudoku();
	cout << checkSudoku << endl;
	
	cout << "Number of Games Played: " << gamesPlayed << endl;

	int goodMoves = checkSudoku.getGoodMoves();
	if (goodMoves == -1) {
		cout << "\nComplete the Sudoku in order to see the comprehensive review of thy solution!" << endl;
	}
	else {
		cout << "\nGood Moves: " << goodMoves << endl;
		cout << "Bad Moves:  " << 81 - goodMoves << endl;
	}
}

void Game::help()
{
	cout << "      *********" << endl;
	cout << "      * HELP! *" << endl;
	cout << "      *********" << endl;

	cout << "\n[New Game]           - Starts a new game by generating a new Sudoku board" << endl;
	cout << "[Reset Game]         - If the game was not saved in file but the board was modified, this will retrieve the latest saved board" << endl;
	cout << "[Reset Game Counter] - Resets the game counter that is displayed via 'Check Stats'" << endl;
	cout << "[Auto Solve]         - Solves the current suodku by a computer" << endl;
	cout << "[Check Stats]        - Loads the current board from the Sudoku.txt and displays the statsistics of how well the board was solved as well as the current number of the games played (this menu option is used to load users solution of the sudoku)" << endl;
	cout << "[Print]              - Displays the Sudoku board\n" << endl;
}

void Game::printSudoku() {
	cout << fileHandler.loadSudoku();
}

void Game::menu() {
	cout << "      *****************************" << endl;
	cout << "      *  WELCOME TO SUDOKUSPHERE! *" << endl;
	cout << "      *****************************" << endl;
	bool izlaz = false;
	while (!izlaz) {
		cout << "\n[1] - New Game" << endl;
		cout << "[2] - Reset Game" << endl;
		cout << "[3] - Reset Game Counter" << endl;
		cout << "[4] - Auto Solve" << endl;
		cout << "[5] - Check Stats" << endl;
		cout << "[6] - Print" << endl;
		cout << "[7] - Help" << endl;
		cout << "[X] - Exit" << endl;
		cout << "\nEnter your choice: ";
		char input;
		cin >> input;
		switch (input)
		{
		case '1':
			system("CLS");
			generateSudoku(69);
			break;
		case '2':
			system("CLS");
			resetSudoku();
			break;
		case '3':
			system("CLS");
			resetConfig();
			break;
		case '4':
			system("CLS");
			solveSudoku();
			break;
		case '5':
			system("CLS");
			printStats();
			break;
		case '6':
			system("CLS");
			printSudoku();
			break;
		case '7':
			system("CLS");
			help();
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