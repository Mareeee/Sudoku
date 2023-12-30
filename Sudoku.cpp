#include "Sudoku.hpp"
using namespace std;

Sudoku9::Sudoku9() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = 0;
        }
    }
}

bool Sudoku9::isValidMove(int row, int col, int num) const {
    for (int i = 0; i < 9; ++i) {
        if ((i != col && board[row][i] == num) or (i != row && board[i][col] == num)) {
            return false;
        }
    }

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

    if (!findEmptyCell(row, col)) {
        return true;
    }

    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(row, col, num)) {
            board[row][col] = num;

            if (solve()) {
                return true;
            }

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

ostream& operator<<(ostream& out, const Sudoku9& sudoku)
{
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

bool operator==(const Sudoku9& originalSudoku, const Sudoku9& compareSudoku)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (originalSudoku.board[i][j] != compareSudoku.board[i][j]) {
                return false;
            }
        }
    }
    return true;
}