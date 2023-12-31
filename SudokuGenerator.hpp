#ifndef SUDOKU_GENERATOR_HPP
#define SUDOKU_GENERATOR_HPP

#include "Sudoku.hpp"

/**
 * @brief This file contains the declaration of the SudokuGenerator class,
 *         responsible for generating Sudoku puzzles.
 *
 * @details The SudokuGenerator class provides functions to shuffle rows and
 *           columns, remove numbers, generate random Sudoku puzzles, and
 *           validate Sudoku puzzles.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

class SudokuGenerator {
public:
    /**
     * @brief Removes excess numbers from the Sudoku puzzle.
     * @param sudoku The Sudoku puzzle.
     */
    Sudoku9 generateRandomSudoku(int numToRemove) const;

    /**
     * @brief Shuffles the rows of the Sudoku puzzle.
     * @param sudoku The Sudoku puzzle to shuffle.
     */
    void shuffleRows(Sudoku9& sudoku) const;

    /**
     * @brief Shuffles the columns of the Sudoku puzzle.
     * @param sudoku The Sudoku puzzle to shuffle.
     */
    void shuffleCols(Sudoku9& sudoku) const;

    /**
     * @brief Removes numbers from the Sudoku puzzle.
     * @param sudoku The Sudoku puzzle.
     * @param numToRemove The number of elements to remove.
     */
    void removeNumbers(Sudoku9& sudoku, int numToRemove) const;

    /**
     * @brief Generates a random Sudoku puzzle.
     * @param numToRemove The number of elements to remove from the generated puzzle.
     * @return The generated Sudoku puzzle.
     */
    void removeExcess(Sudoku9& sudoku) const;
};
#endif