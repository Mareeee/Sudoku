#ifndef SUDOKU_GENERATOR_HPP
#define SUDOKU_GENERATOR_HPP

#include "Sudoku.hpp"

/**
 * @brief This file contains the declaration of the SudokuGenerator class,
 *         responsible for generating Sudoku puzzles.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

class SudokuGenerator {
public:
    /**
     * @brief Removes excess numbers from the Sudoku puzzle.
     * @param sudoku The Sudoku puzzle.
     * @return The generated Sudoku puzzle.
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
     * 
     * randIndex is the randomly generated index within the current range (excluding elements already removed).
     * cellPositions[randIndex] represents the element at the randomly chosen index.
     * cellPositions[static_cast<size_t>(81 - k - 1)] represents the element at the end of the vector, considering the elements already removed (k elements removed so far).
     */
    void removeNumbers(Sudoku9& sudoku, int numToRemove) const;

    /**
     * @brief Removes excess numbers from the Sudoku puzzle by going through every submatrix and checking
     *  whether it containts > 6 numbers. If so, it stops adding numbers to the submatrix.
     * @param sudoku The Sudoku puzzle.
     */
    void removeExcess(Sudoku9& sudoku) const;
};
#endif