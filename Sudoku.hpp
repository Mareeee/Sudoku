#pragma once
#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
using namespace std;

class Sudoku9 {
    int board[9][9];
    bool findEmptyCell(int& row, int& col) const;

public:
    Sudoku9();
    void print() const;
    bool isValidMove(int row, int col, int num) const;
    int getCellValue(int row, int col) const;
    void setCellValue(int row, int col, int value);
    void swapRows(int row1, int row2);
    void swapCols(int col1, int col2);
    bool solve();
};
#endif