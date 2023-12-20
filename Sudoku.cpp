#include "Sudoku.hpp"
using namespace std;

Sudoku::Sudoku() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            table[i][j] = 0;
        }
    }
}

void Sudoku::print() const {
    cout << "    --------------BOARD--------------" << endl;
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            cout << "    ----------+----------+-----------" << endl;
        }

        cout << 9 - i << "   |";

        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }

            if (table[i][j] == 0) {
                cout << " 0 ";
            }
            else {
                cout << " " << table[i][j] << " ";
            }

            if (j == 8) {
                cout << "|";
            }
        }
        cout << endl;
    }
    cout << "    ----------+----------+-----------" << endl;
    cout << "\n      A  B  C    D  E  F    G  H  I" << endl;
}

bool Sudoku::isValidMove(int row, int col, int num) const {
    for (int i = 0; i < 9; ++i) {
        if (table[row][i] == num || table[i][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (table[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::solve() {
    int row, col;

    if (!findEmptyCell(row, col)) {
        return true;
    }

    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(row, col, num)) {
            table[row][col] = num;

            if (solve()) {
                return true;
            }

            table[row][col] = 0;
        }
    }

    return false;
}

bool Sudoku::findEmptyCell(int& row, int& col) const {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (table[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}