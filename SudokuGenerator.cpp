/**
 * @brief This file contains the implementation of the SudokuGenerator class,
 *         responsible for generating Sudoku puzzles.
 *
 * @details The SudokuGenerator class provides functions to shuffle rows and
 *           columns, remove numbers, generate random Sudoku puzzles, and
 *           validate Sudoku puzzles.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include "SudokuGenerator.hpp"
#include <vector>

 /**
  * @brief Randomly shuffles the rows of the Sudoku puzzle.
  * @param sudoku The Sudoku puzzle to shuffle.
  */
void SudokuGenerator::shuffleRows(Sudoku9& sudoku) const {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; ++j) {
            int randIndex = i + rand() % 3;
            sudoku.swapRows(i + j, randIndex);
        }
    }
}

/**
 * @brief Randomly shuffles the columns of the Sudoku puzzle.
 * @param sudoku The Sudoku puzzle to shuffle.
 */
void SudokuGenerator::shuffleCols(Sudoku9& sudoku) const {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; ++j) {
            int randIndex = i + rand() % 3;
            sudoku.swapCols(i + j, randIndex);
        }
    }
}

/**
 * @brief Removes numbers from the Sudoku puzzle.
 * @param sudoku The Sudoku puzzle.
 * @param numToRemove The number of elements to remove.
 * 
 * randIndex is the randomly generated index within the current range (excluding elements already removed).
 * cellPositions[randIndex] represents the element at the randomly chosen index.
 * cellPositions[static_cast<size_t>(81 - k - 1)] represents the element at the end of the vector, considering the elements already removed (k elements removed so far).
 */
void SudokuGenerator::removeNumbers(Sudoku9& sudoku, int numToRemove) const {
    vector<pair<int, int>> cellPositions;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cellPositions.push_back({ i, j });
        }
    }

    for (int k = 0; k < numToRemove; ++k) {
        int randIndex = rand() % (81 - k);
        int i = cellPositions[randIndex].first;
        int j = cellPositions[randIndex].second;
        cellPositions[randIndex] = cellPositions[static_cast<size_t>(81 - k - 1)];
        sudoku.setCellValue(i, j, 0);
    }
}

/**
 * @brief Generates a random Sudoku puzzle.
 * @param numToRemove The number of elements to remove from the generated puzzle.
 * @return The generated Sudoku puzzle.
 */
Sudoku9 SudokuGenerator::generateRandomSudoku(int numToRemove) const {
    /**
     * This line initializes the random number generator using the current time as a seed.
     * It ensures that the sequence of random numbers generated will be different in each run of the program.
     */
    srand(static_cast<unsigned>(time(nullptr)));
    
    /**
     * 
     * The solve method is called on the sudoku object. 
     *  This method fills in the Sudoku grid with a complete and valid solution.
     *  This step ensures that the generated Sudoku is solvable and has a unique solution.
     */
    Sudoku9 sudoku;
    sudoku.solve();
    
    /**
     * The functions shuffleRows and shuffleCols are responsible for shuffling 
     *  the rows and columns of the Sudoku grid, respectively. 
     * The shuffling is done in groups of three, maintaining the integrity of the 3x3 subgrids.
     * This step introduces variation to the Sudoku layout while preserving its solvability.
     */
    shuffleRows(sudoku);
    shuffleCols(sudoku);

    /**
     * The removeNumbers function takes the Sudoku grid and the desired number of cells (numToRemove) to be removed.
     * It randomly selects cells and sets their values to zero, effectively removing numbers from the Sudoku grid. 
     * The randomness is introduced by shuffling the order in which the cells are considered for removal. 
     * This step creates the puzzle aspect of Sudoku, leaving the player with a partially filled grid to solve.
     */
    removeNumbers(sudoku, numToRemove);

    /**
     * The removeExcess function further modifies the Sudoku grid by removing excess numbers, 
     *  ensuring a unique and interesting puzzle. 
     *  It scans each 3x3 subgrid and removes numbers until only a certain number of filled cells remain.
     */
    removeExcess(sudoku);

    return sudoku;
}

/**
 * @brief Removes excess numbers from the Sudoku puzzle by going through every submatrix and checking
 *  whether it containts > 6 numbers. If so, it stops adding numbers to the submatrix.
 * @param sudoku The Sudoku puzzle.
 */
void SudokuGenerator::removeExcess(Sudoku9& sudoku) const {
    const int rows = 9;
    const int cols = 9;

    for (int i = 0; i < rows; i += 3) {
        for (int j = 0; j < cols; j += 3) {
            int counter = 0;
            for (int row = i; row < i + 3; ++row) {
                for (int col = j; col < j + 3; ++col) {
                    if (sudoku.getCellValue(row, col) != 0) {
                        ++counter;
                    }
                    if (counter > 6) {
                        sudoku.setCellValue(row, col, 0);
                    }
                }
            }
        }
    }
}