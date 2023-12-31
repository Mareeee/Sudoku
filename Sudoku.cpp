/**
 * @brief Implementation of the Sudoku class for a 9x9 Sudoku board.
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include "Sudoku.hpp"
using namespace std;

/**
 * @brief Default constructor for the Sudoku class.
 * Initializes the Sudoku board with all cells set to 0.
 */
Sudoku9::Sudoku9() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = 0;
        }
    }
}

/**
 * @brief Counts the number of valid moves in the Sudoku puzzle. If a 0 is found, the whole sudoku is
 *  invalid and -1 is returned.
 * @param sudoku The Sudoku puzzle.
 * @return The number of valid moves.
 */
int Sudoku9::getGoodMoves() const {
    int goodMoves = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int currentValue = board[i][j];
            if (currentValue == 0) {
                return -1;
            }
            if (isValidMove(i, j, currentValue)) {
                ++goodMoves;
            }
        }
    }
    return goodMoves;
}

/**
 * @brief Checks if the Sudoku puzzle is completely filled.
 * @param sudoku The Sudoku puzzle.
 * @return True if the puzzle is filled, false otherwise.
 */
bool Sudoku9::isFilled() const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int currentValue = board[i][j];
            if (currentValue == 0) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Checks if placing a number at a specific position is a valid move.
 * @param row The row index.
 * @param col The column index.
 * @param num The number to be placed.
 * @return True if the move is valid, false otherwise.
 */
bool Sudoku9::isValidMove(int row, int col, int num) const {
    /**
     * Looping through the row and column where the element is positioned at, and checking whether
     *  there are 2 instances of the current element, whilst also
     *  skipping the position where current element is positioned at.
     */
    for (int i = 0; i < 9; ++i) {
        if ((i != col && board[row][i] == num) or (i != row && board[i][col] == num)) {
            return false;
        }
    }

    /**
     * Looping through submatrix and checking whether there are 2 instances of the current element, whilst also
     *  skipping the position where current element is positioned at.
     */
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((startRow + i) != row && (startCol + j) != col && board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Solves the Sudoku puzzle using a backtracking algorithm.
 * @return True if the puzzle is solvable, false otherwise.
 */
bool Sudoku9::solve() {
    int row, col;

    /**
     * Base Case
     * The findEmptyCell function purpose is to locate the next empty cell (cell with a value of 0) 
     *  in the Sudoku grid. If no empty cell is found, the puzzle is considered solved, 
     *  and the function returns true.
     */
    if (!findEmptyCell(row, col)) {
        return true;
    }

    /**
     * Recursive Backtracking
     * The function enters a loop from 1 to 9, representing possible values for the current empty cell.
     * For each value (num), it checks if placing num in the current cell (row, col) is a valid move using the isValidMove function.
     * If the move is valid, the value num is placed in the cell, and the solve function is called recursively.
     * If the recursive call returns true, it means a solution is found, and the function returns true.
     * If the recursive call returns false, the placed value is reset to 0 (board[row][col] = 0), and the loop continues with the next value. 
     */
    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(row, col, num)) {
            board[row][col] = num;

            if (solve()) {
                return true;
            }

            /**
             * Backtracking
             * If none of the values in the loop lead to a valid solution, 
             *  the function backtracks by resetting the current cell to 0 and returns false.
             */
            board[row][col] = 0;
        }
    }
    return false;
}

/**
 * @brief Finds the first empty cell in the Sudoku board.
 * @param row Reference to store the row index.
 * @param col Reference to store the column index.
 * @return True if an empty cell is found, false if the board is full.
 */
bool Sudoku9::findEmptyCell(int& row, int& col) const {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Gets the value of a cell at a specific position.
 * @param row The row index.
 * @param col The column index.
 * @return The value of the cell.
 */
int Sudoku9::getCellValue(int row, int col) const {
    return board[row][col];
}

/**
 * @brief Sets the value of a cell at a specific position.
 * @param row The row index.
 * @param col The column index.
 * @param value The value to be set.
 */
void Sudoku9::setCellValue(int row, int col, int value) {
    board[row][col] = value;
}

/**
 * @brief Swaps two rows in the Sudoku board.
 * @param row1 The index of the first row.
 * @param row2 The index of the second row.
 */
void Sudoku9::swapRows(int row1, int row2) {
    for (int col = 0; col < 9; ++col) {
        swap(board[row1][col], board[row2][col]);
    }
}

/**
 * @brief Swaps two columns in the Sudoku board.
 * @param col1 The index of the first column.
 * @param col2 The index of the second column.
 */
void Sudoku9::swapCols(int col1, int col2) {
    for (int row = 0; row < 9; ++row) {
        swap(board[row][col1], board[row][col2]);
    }
}

/**
 * @brief Overloaded << operator to output the Sudoku board.
 * @param out The output stream.
 * @param sudoku The Sudoku object to be printed.
 * @return The output stream after printing the board.
 */
ostream& operator<<(ostream& out, const Sudoku9& sudoku) {
    out << "\n        ----------BOARD----------" << endl;
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            out << "        --------+-------+--------" << endl;
        }

        out << "        | ";

        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                out << "| ";
            }

            if (sudoku.board[i][j] == 0) {
                out << "  ";
            }
            else {
                out << sudoku.board[i][j] << " ";
            }

            if (j == 8) {
                out << "|";
            }
        }
        out << endl;
    }
    out << "        -------------------------" << endl;
    return out;
}

/**
 * @brief Overloaded == operator to compare two Sudoku boards for equality.
 * @param originalSudoku The first Sudoku object.
 * @param compareSudoku The second Sudoku object.
 * @return True if the boards are equal, false otherwise.
 */
bool operator==(const Sudoku9& originalSudoku, const Sudoku9& compareSudoku) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (originalSudoku.board[i][j] != compareSudoku.board[i][j]) {
                return false;
            }
        }
    }
    return true;
}