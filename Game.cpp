#include "SudokuGenerator.hpp"
#include "Sudoku.hpp"
#include "Game.hpp"

Game::Game(string filepath) : gamesPlayed(0), filepath(filepath) {
	sudoku = loadSudoku(filepath);
}

void Game::solveSudoku() {
	sudoku.solve();
	sudoku.print();
}

void Game::generateSudoku(int numToRemove) {
	system("CLS");
	sudoku = generateRandomSudoku(numToRemove);
	saveSudoku(sudoku, filepath);
	++gamesPlayed;
}

void Game::printStats() {
	system("CLS");
	cout << "\n      ******************" << endl;
	cout << "      *  SUDOKU STATS! *" << endl;
	cout << "      ******************" << endl;
	cout << "\nNumber of Games Played: " << gamesPlayed << endl;
	cout << "\nGood Moves: " << getGoodMoves(sudoku) << endl;
	cout << "Bad Moves:  " << getBadMoves(sudoku) << endl;
}

void Game::printSudoku() {
	sudoku.print();
}