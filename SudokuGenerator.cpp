#include "SudokuGenerator.hpp"
#include "Sudoku.hpp"
#include <vector>

void SudokuGenerator::shuffleRows(Sudoku& sudoku) const {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; ++j) {
            int randIndex = i + rand() % 3;
            sudoku.swapRows(i + j, randIndex);
        }
    }
}

void SudokuGenerator::shuffleCols(Sudoku& sudoku) const {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; ++j) {
            int randIndex = i + rand() % 3;
            sudoku.swapCols(i + j, randIndex);
        }
    }
}

void SudokuGenerator::removeNumbers(Sudoku& sudoku, int numToRemove) const {
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
        //cellPositions[randIndex] = cellPositions[81 - k - 1];
        sudoku.setCellValue(i, j, 0);
    }
}

Sudoku SudokuGenerator::generateRandomSudoku(int numToRemove) const {
    Sudoku sudoku;

    sudoku.solve();
    shuffleRows(sudoku);
    shuffleCols(sudoku);
    removeNumbers(sudoku, numToRemove);

    return sudoku;
}
