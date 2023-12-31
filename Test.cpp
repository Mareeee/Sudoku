/**
 * This file contains the implementation of the Test class, which is responsible
 * for running various test cases on the Sudoku game.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include "Test.hpp"
using namespace std;

/**
 * @brief Constructs a Test object.
 *
 * Initializes the Test object with the provided file paths and sets the
 * gamesPlayed counter to 0.
 *
 * @param sudokuFilepath The file path for Sudoku data.
 * @param configFilepath The file path for configuration data.
 */
Test::Test(const string sudokuFilepath, const string configFilepath) : fileHandler(sudokuFilepath, configFilepath), sudoku(fileHandler.loadSudoku()), gamesPlayed(0) {}

/**
 * @brief Runs all test cases.
 *
 * Outputs the results of various test cases related to Sudoku game functionality.
 */
void Test::runAll() {
	cout << "Running Test Cases..." << endl;
	cout << "\nTest #1: " << (createRandomSudokuBoardTest() ? "Success" : "Fail") << endl;
	cout << "Test #2: " << (autocompleteSudokuTest() ? "Success" : "Fail") << endl;
	cout << "Test #3: " << (faultySudokuTest() ? "Success" : "Fail") << endl;
	cout << "Test #4: " << (gameCounterTest() ? "Success" : "Fail") << endl;
	cout << "Test #5: " << (fileHandlingTest() ? "Success" : "Fail") << endl;
}

/**
 * @brief Tests the creation of a random Sudoku board.
 *
 * Generates a random Sudoku board and checks if it is not equal to the empty Sudoku board.
 *
 * @return True if the test is successful, false otherwise.
 */
bool Test::createRandomSudokuBoardTest() {
	sudoku = sudokuGenerator.generateRandomSudoku(69);
	return (sudoku == emptySudoku) ? false : true;
}

/**
 * @brief Tests the autocompletion of a Sudoku board.
 *
 * Solves the Sudoku board and checks if it is fully filled.
 *
 * @return True if the test is successful, false otherwise.
 */
bool Test::autocompleteSudokuTest() {
	sudoku.solve();
	return sudoku.isFilled() ? true : false;
}

/**
 * @brief Tests a faulty Sudoku scenario.
 *
 * Modifies a Sudoku board to introduce a fault by copying and pasting the first value on the board to the second place on it.
 * Then checks if the number of good moves is not 81 (max number of good moves).
 * The test number of good moves should not equal to the 81 since the content of the board was modified.
 *	
 * @return True if the test is successful, false otherwise.
 */
bool Test::faultySudokuTest() {
	int boardValue11 = sudoku.getCellValue(0, 0);
	sudoku.setCellValue(0, 1, boardValue11);
	return (sudoku.getGoodMoves() == 81) ? false : true;
}

/**
 * @brief Tests the game counter functionality.
 *
 * Increments the gamesPlayed counter and checks if it becomes 1.
 *
 * @return True if the test is successful, false otherwise.
 */
bool Test::gameCounterTest() {
	if (createRandomSudokuBoardTest()) {
		++gamesPlayed;
	}
	return (gamesPlayed == 1) ? true : false;
}

/**
 * @brief Tests file handling operations.
 *
 * Saves and loads a Sudoku board and gamesPlayed counter, then checks if they match.
 *
 * @return True if the test is successful, false otherwise.
 */
bool Test::fileHandlingTest() {
	fileHandler.save(sudoku, gamesPlayed);
	Sudoku9 loadedSudoku = fileHandler.loadSudoku();
	int loadedGamesPlayed = fileHandler.loadConfig();
	return ((sudoku == loadedSudoku) && gamesPlayed == loadedGamesPlayed) ? true : false;
}