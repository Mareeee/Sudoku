#include "Test.hpp"
using namespace std;

Test::Test(const string sudokuFilepath, const string configFilepath) : fileHandler(sudokuFilepath, configFilepath), sudoku(fileHandler.loadSudoku()), gamesPlayed(0) {}

void Test::runAll() {
	cout << "Running Test Cases..." << endl;
	cout << "\nTest #1: " << (createRandomSudokuBoard() ? "Success" : "Fail") << endl;
	cout << "Test #2: " << (autocompleteSudoku() ? "Success" : "Fail") << endl;
	cout << "Test #3: " << (faultySudoku() ? "Success" : "Fail") << endl;
	cout << "Test #4: " << (gameCounter() ? "Success" : "Fail") << endl;
	cout << "Test #5: " << (fileHandling() ? "Success" : "Fail") << endl;
}

bool Test::createRandomSudokuBoard() {
	sudoku = sudokuGenerator.generateRandomSudoku(69);
	return (sudoku == emptySudoku) ? false : true;
}

bool Test::autocompleteSudoku() {
	sudoku.solve();
	return sudokuGenerator.isFilled(sudoku) ? true : false;
}

bool Test::faultySudoku() {
	int boardValue11 = sudoku.getCellValue(0, 0);
	sudoku.setCellValue(0, 1, boardValue11);
	return (sudokuGenerator.getGoodMoves(sudoku) == 81) ? false : true;
}

bool Test::gameCounter() {
	if (createRandomSudokuBoard()) {
		++gamesPlayed;
	}
	return (gamesPlayed == 1) ? true : false;
}

bool Test::fileHandling() {
	fileHandler.save(sudoku, gamesPlayed);
	Sudoku9 loadedSudoku = fileHandler.loadSudoku();
	int loadedGamesPlayed = fileHandler.loadConfig();
	return ((sudoku == loadedSudoku) && gamesPlayed == loadedGamesPlayed) ? true : false;
}
