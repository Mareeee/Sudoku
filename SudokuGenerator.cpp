#include "SudokuGenerator.hpp"
#include <vector>

void SudokuGenerator::shuffleRows(Sudoku9& sudoku) const {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; ++j) {
            int randIndex = i + rand() % 3;
            sudoku.swapRows(i + j, randIndex);
        }
    }
}

void SudokuGenerator::shuffleCols(Sudoku9& sudoku) const {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; ++j) {
            int randIndex = i + rand() % 3;
            sudoku.swapCols(i + j, randIndex);
        }
    }
}

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
        cellPositions[randIndex] = cellPositions[81 - k - 1];
        sudoku.setCellValue(i, j, 0);
    }
}

Sudoku9 SudokuGenerator::generateRandomSudoku(int numToRemove) const {
    srand(static_cast<unsigned>(time(nullptr)));
    Sudoku9 sudoku;

    sudoku.solve();
    shuffleRows(sudoku);
    shuffleCols(sudoku);
    removeNumbers(sudoku, numToRemove);
    removeExcess(sudoku);

    return sudoku;
}

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

int SudokuGenerator::getGoodMoves(const Sudoku9& sudoku) {
    int goodMoves = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int currentValue = sudoku.getCellValue(i, j);
            if (currentValue == 0) {
                return -1;
            }
            if (sudoku.isValidMove(i, j, currentValue)) {
                ++goodMoves;
            }
        }
    }
    return goodMoves;
}

int SudokuGenerator::getBadMoves(const Sudoku9& sudoku) {
    int badMoves = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int currentValue = sudoku.getCellValue(i, j);
            if (currentValue == 0) {
                return -1;
            }
            if (!sudoku.isValidMove(i, j, currentValue)) {
                ++badMoves;
            }
        }
    }
    return badMoves;
}

bool SudokuGenerator::isFilled(const Sudoku9& sudoku) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int currentValue = sudoku.getCellValue(i, j);
            if (currentValue == 0) {
                return false;
            }
        }
    }
    return true;
}
