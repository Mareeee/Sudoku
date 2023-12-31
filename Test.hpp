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
    Test(const std::string sudokuFilepath, const std::string configFilepath);

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
     * Modifies a Sudoku board to introduce a fault and checks if the number of
     * good moves is not 81.
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
     * @brief Tests the creation of a random Sudoku board.
     *
     * Generates a random Sudoku board and checks if it is not equal to the empty Sudoku board.
     *
     * @return True if the test is successful, false otherwise.
     */
    bool createRandomSudokuBoardTest();
};
#endif