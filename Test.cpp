/**
 * This file contains the implementation of the Test class, which is responsible
 * for running various test cases on the Sudoku game.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include <chrono>
#include "Test.hpp"
using namespace std;

Test::Test(const string sudokuFilepath, const string configFilepath) : fileHandler(sudokuFilepath, configFilepath), sudoku(fileHandler.loadSudoku()), gamesPlayed(0) {}

void Test::runAll() {
	cout << "Running Test Cases..." << endl;
	cout << "\nTest #1: " << (createRandomSudokuBoardTest() ? "Success" : "Fail") << endl;
	cout << "Test #2: " << (autocompleteSudokuTest() ? "Success" : "Fail") << endl;
	cout << "Test #3: " << (faultySudokuTest() ? "Success" : "Fail") << endl;
	cout << "Test #4: " << (gameCounterTest() ? "Success" : "Fail") << endl;
	cout << "Test #5: " << (fileHandlingTest() ? "Success" : "Fail") << endl;
	cout << "Test #6: " << (resetConfigTest() ? "Success" : "Fail") << endl;
	cout << "Test #7: " << (removeExcessTest() ? "Success" : "Fail") << endl;
	speedTest();
}

bool Test::createRandomSudokuBoardTest() {
	sudoku = sudokuGenerator.generateRandomSudoku(69);
	return (sudoku == emptySudoku) ? false : true;
}

bool Test::autocompleteSudokuTest() {
	sudoku.solve();
	return sudoku.isFilled() ? true : false;
}

bool Test::faultySudokuTest() {
	int boardValue11 = sudoku.getCellValue(0, 0);
	sudoku.setCellValue(0, 1, boardValue11);
	return (sudoku.getGoodMoves() == 81) ? false : true;
}

bool Test::gameCounterTest() {
	if (createRandomSudokuBoardTest()) {
		++gamesPlayed;
	}
	return (gamesPlayed == 1) ? true : false;
}

bool Test::fileHandlingTest() {
	fileHandler.save(sudoku, gamesPlayed);
	Sudoku9 loadedSudoku = fileHandler.loadSudoku();
	int loadedGamesPlayed = fileHandler.loadConfig();
	return ((sudoku == loadedSudoku) && gamesPlayed == loadedGamesPlayed) ? true : false;
}

bool Test::resetConfigTest() {
	fileHandler.clearConfig();
	int gamesPlayedCleared = fileHandler.loadConfig();
	return (gamesPlayed == gamesPlayedCleared) ? false : true;
}

bool Test::removeExcessTest() {
	sudoku.solve();
	sudokuGenerator.removeExcess(sudoku);
	return sudoku.isFilled() ? false : true;
}

static long long measureTime(string filename) {
	// Start measuring time
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

	File googleFile = File(filename, "");
	googleFile.loadSudoku().solve();

	// Stop measuring time
	chrono::high_resolution_clock::time_point stop = chrono::high_resolution_clock::now();

	chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	return duration.count();
}

void Test::speedTest() {
	cout << "Time to solve: " << endl;
	cout << "	-Google Sudoku: " << measureTime("test/GoogleSudoku.txt") << " microseconds" << endl;
	cout << "	-Easy Sudoku: " << measureTime("test/EasySudoku.txt") << " microseconds" << endl;
	cout << "	-Medium Sudoku: " << measureTime("test/MediumSudoku.txt") << " microseconds" << endl;
	cout << "	-Hard Sudoku: " << measureTime("test/HardSudoku.txt") << " microseconds" << endl;
	cout << "	-Expert Sudoku: " << measureTime("test/ExpertSudoku.txt") << " microseconds" << endl;
}