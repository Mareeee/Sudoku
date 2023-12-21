#include "SudokuGenerator.hpp"
#include "Sudoku.hpp"
#include "Game.hpp"

void Game::generateSudoku(string filepath, int numToRemove) {
	Sudoku randomSudoku = generateRandomSudoku(numToRemove);
	saveSudoku(randomSudoku, filepath);
}

void Game::printSudoku(string filepath) {
	Sudoku loadedSudoku = loadSudoku(filepath);
	loadedSudoku.print();
}

void Game::solveSudoku(string filepath) {
	Sudoku loadedSudoku = loadSudoku(filepath);
	loadedSudoku.solve();
	loadedSudoku.print();
}
