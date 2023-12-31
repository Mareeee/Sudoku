#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
using namespace std;

/**
 * This file contains the declaration of the Sudoku class, representing
 *  a 9x9 Sudoku board. It includes member functions for solving the puzzle,
 *  checking the validity of moves, and various operations on the Sudoku board.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

class Sudoku9 {
    int board[9][9];    /**< The 9x9 Sudoku board. */

    /**
     * @brief Finds the first empty cell in the Sudoku board.
     * @param row Reference to the row index of the empty cell.
     * @param col Reference to the column index of the empty cell.
     * @return True if an empty cell is found, false otherwise.
     */
    bool findEmptyCell(int& row, int& col) const;

public:
    /**
     * @brief Default constructor for the Sudoku class.
     * Initializes the Sudoku board with all cells set to 0.
     */
    Sudoku9();

    /**
     * @brief Counts the number of valid moves in the Sudoku puzzle.
     * @param sudoku The Sudoku puzzle.
     * @return The number of valid moves.
     */
    int getGoodMoves() const;

    /**
     * @brief Checks if the Sudoku puzzle is completely filled.
     * @param sudoku The Sudoku puzzle.
     * @return True if the puzzle is filled, false otherwise.
     */
    bool isFilled() const;

    /**
     * @brief Checks if placing a number at a specific position is a valid move.
     * @param row The row index.
     * @param col The column index.
     * @param num The number to be placed.
     * @return True if the move is valid, false otherwise.
     */
    bool isValidMove(int row, int col, int num) const;

    /**
     * @brief Gets the value of a cell at a specific position.
     * @param row The row index.
     * @param col The column index.
     * @return The value of the cell.
     */
    int getCellValue(int row, int col) const;

    /**
     * @brief Sets the value of a cell at a specific position.
     * @param row The row index.
     * @param col The column index.
     * @param value The value to be set.
     */
    void setCellValue(int row, int col, int value);

    /**
     * @brief Swaps two rows in the Sudoku board.
     * @param row1 The index of the first row.
     * @param row2 The index of the second row.
     */
    void swapRows(int row1, int row2);

    /**
     * @brief Swaps two columns in the Sudoku board.
     * @param col1 The index of the first column.
     * @param col2 The index of the second column.
     */
    void swapCols(int col1, int col2);

    /**
     * @brief Solves the Sudoku puzzle using a backtracking algorithm.
     * @return True if the puzzle is solvable, false otherwise.
     */
    bool solve();

    /**
     * @brief Overloaded << operator to output the Sudoku board.
     * @param out The output stream.
     * @param sudoku The Sudoku object to be printed.
     * @return The output stream after printing the board.
     */
    friend ostream& operator<< (ostream& out, const Sudoku9& sudoku);

    /**
     * @brief Overloaded == operator to compare two Sudoku boards for equality.
     * @param originalSudoku The first Sudoku object.
     * @param compareSudoku The second Sudoku object.
     * @return True if the boards are equal, false otherwise.
     */
    friend bool operator==(const Sudoku9& originalSudoku, const Sudoku9& compareSudoku);
};
#endif