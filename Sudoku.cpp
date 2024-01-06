/**
 * @brief Implementation of the Sudoku class for a 9x9 Sudoku board.
 * 
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include "Sudoku.hpp"
using namespace std;

Sudoku9::Sudoku9() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = 0;
        }
    }
}

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

bool Sudoku9::isValidMove(int row, int col, int num) const {
    // Looping through the row and column where the element is positioned at, and checking whether
    //  there are 2 instances of the current element, whilst also
    //  skipping the position where current element is positioned at.
    for (int i = 0; i < 9; ++i) {
        if ((i != col && board[row][i] == num) or (i != row && board[i][col] == num)) {
            return false;
        }
    }

     // Looping through submatrix and checking whether there are 2 instances of the current element, whilst also
     //  skipping the position where current element is positioned at.
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

bool Sudoku9::solve() {
    int row, col;

     // Base Case
     // The findEmptyCell function purpose is to locate the next empty cell (cell with a value of 0) 
    if (!findEmptyCell(row, col)) {
        return true;
    }

     // Recursive Backtracking
     // The function enters a loop from 1 to 9, representing possible values for the current empty cell.
     // For each value (num), it checks if placing num in the current cell (row, col) is a valid move using the isValidMove function.
    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(row, col, num)) {
            board[row][col] = num;

            if (solve()) {
                return true;
            }

             // Backtracking
             // If none of the values in the loop lead to a valid solution, 
             //  the function backtracks by resetting the current cell to 0 and returns false.
            board[row][col] = 0;
        }
    }
    return false;
}

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

int Sudoku9::getCellValue(int row, int col) const {
    return board[row][col];
}

void Sudoku9::setCellValue(int row, int col, int value) {
    board[row][col] = value;
}

void Sudoku9::swapRows(int row1, int row2) {
    for (int col = 0; col < 9; ++col) {
        swap(board[row1][col], board[row2][col]);
    }
}

void Sudoku9::swapCols(int col1, int col2) {
    for (int row = 0; row < 9; ++row) {
        swap(board[row][col1], board[row][col2]);
    }
}

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