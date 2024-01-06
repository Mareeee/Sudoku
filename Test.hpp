#ifndef TEST_HPP
#define TEST_HPP

#include "File.hpp"
#include "SudokuGenerator.hpp"

/**
 * This file contains the declaration of the Test class, which is responsible
 * for running various test cases on the Sudoku game.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

class Test {
	File fileHandler;				 /**< Handles file operations. */
	SudokuGenerator sudokuGenerator; /**< Generates Sudoku boards. */
	Sudoku9 sudoku;					 /**< Represents a Sudoku board for testing. */
	Sudoku9 emptySudoku;			 /**< Represents an empty Sudoku board for comparison. */
	int gamesPlayed;				 /**< Counter for the number of games played. */

public:
    /**
     * @brief Constructs a Test object.
     *
     * Initializes the Test object with the provided file paths and sets the
     * gamesPlayed counter to 0.
     *
     * @param sudokuFilepath The file path for Sudoku data.
     * @param configFilepath The file path for configuration data.
     */
    Test(const string sudokuFilepath, const string configFilepath);

    /**
     * @brief Runs all test cases.
     * Outputs the results of various test cases related to Sudoku game functionality.
     */
    void runAll();

    /**
     * @brief Tests the autocompletion of a Sudoku board.
     *
     * Solves the Sudoku board and checks if it is fully filled.
     *
     * @return True if the test is successful, false otherwise.
     */
    bool autocompleteSudokuTest();

    /**
     * @brief Tests a faulty Sudoku scenario.
     *
     * Modifies a Sudoku board to introduce a fault by copying and pasting the first value on the board to the second place on it.
     * Then checks if the number of good moves is not 81 (max number of good moves).
     * The test number of good moves should not equal to the 81 since the content of the board was modified.
     *
     * @return True if the test is successful, false otherwise.
     */
    bool faultySudokuTest();

    /**
     * @brief Tests the game counter functionality.
     *
     * Increments the gamesPlayed counter and checks if it becomes 1.
     *
     * @return True if the test is successful, false otherwise.
     */
    bool gameCounterTest();

    /**
     * @brief Tests file handling operations.
     *
     * Saves and loads a Sudoku board and gamesPlayed counter, then checks if they match.
     *
     * @return True if the test is successful, false otherwise.
     */
    bool fileHandlingTest();

    /**
     * @brief Tests reset games played.
     *
     * Clears the config file, and then loads its contents and checks whether it maches the previous state of the games played.
     *
     * @return True if the test is successful, false otherwise.
     */
    bool resetConfigTest();

    /**
     * @brief Tests removing the excess numbers from submatrices.
     *
     * Solves Sudoku, and then removes the numbers from it and checks whether the current board contains any empty spots.
     *
     * @return True if the test is successful, false otherwise.
     */
    bool removeExcessTest();

    /**
     * @brief Testing the speed of the solving algorithm using the Sudoku boards from a phone game
     */
    void speedTest();

    /**
     * @brief Tests the creation of a random Sudoku board.
     *
     * Generates a random Sudoku board and checks if it is not equal to the empty Sudoku board.
     *
     * @return True if the test is successful, false otherwise.
     */
    bool createRandomSudokuBoardTest();
};
#endif