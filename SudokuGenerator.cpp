#include "SudokuGenerator.hpp"
#include "Sudoku.hpp"
#include <vector>

SudokuGenerator::SudokuGenerator() : goodMoves(0), badMoves(0) {}

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
    Sudoku9 sudoku;

    sudoku.solve();
    shuffleRows(sudoku);
    shuffleCols(sudoku);
    removeNumbers(sudoku, numToRemove);

    return sudoku;
}

int SudokuGenerator::getGoodMoves(const Sudoku9& sudokuOG) {
    Sudoku9 sudoku = sudokuOG;
    goodMoves = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int currentValue = sudoku.getCellValue(i, j);
            if (currentValue == 0) {
                goodMoves = 0;
                return goodMoves;
            }
            if (sudoku.isValidMove(i, j, currentValue)) {
                ++goodMoves;
            }
        }
    }
    return goodMoves;
}

int SudokuGenerator::getBadMoves(const Sudoku9& sudoku) {
    badMoves = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int currentValue = sudoku.getCellValue(i, j);
            if (currentValue == 0) {
                badMoves = 81;
                return badMoves;
            }
            if (!sudoku.isValidMove(i, j, currentValue)) {
                ++badMoves;
            }
        }
    }
    return badMoves;
}
