/**
 * @brief Represents the Sudoku game and provides game-related functionalities.
 * @details The Game class extends SudokuGenerator and provides methods for
 * managing and interacting with the Sudoku game, including generating new games,
 * solving the Sudoku, resetting the game, resetting the game counter, and more.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include "Game.hpp"

 /**
  * @brief Constructor for the Game class.
  * @param sudokuFilepath The filepath for the Sudoku data file.
  * @param configFilepath The filepath for the configuration file.
  */
Game::Game(string sudokuFilepath, string configFilepath) : fileHandler(sudokuFilepath, configFilepath), sudoku(fileHandler.loadSudoku()), gamesPlayed(fileHandler.loadConfig()) {}

/**
 * @brief Resets the current Sudoku game and saves the state.
 */
void Game::resetSudoku() {
	cout << "\n      ******************" << endl;
	cout << "      *  SUDOKU RESET! *" << endl;
	cout << "      ******************" << endl;
	fileHandler.save(sudoku, gamesPlayed);
}

/**
 * @brief Solves the current Sudoku game and saves the solved state.
 */
void Game::solveSudoku() {
	sudoku.solve();
	fileHandler.save(sudoku, gamesPlayed);
	cout << sudoku;
}

/**
 * @brief Resets the game counter by clearing the configuration file.
 * @brief It also asks for the user confirmation when doing so.
 */
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

/**
 * @brief Generates a new Sudoku game with a specified number of cells removed.
 * @param numToRemove The number of cells to be removed from the generated Sudoku.
 */
void Game::generateSudoku(int numToRemove) {
	if (sudoku.isFilled()) {
		++gamesPlayed;
	}
	sudoku = generateRandomSudoku(numToRemove);
	fileHandler.save(sudoku, gamesPlayed);
	cout << sudoku;
}

/**
 * @brief Prints statistics about the current game, including the number of games played,
 * good moves, and bad moves (if the Sudoku is completed).
 */
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

/**
 * @brief Prints the current state of the Sudoku game.
 */
void Game::printSudoku() {
	cout << fileHandler.loadSudoku();
}

/**
 * @brief Displays the main menu and handles user input for various game actions.
 */
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