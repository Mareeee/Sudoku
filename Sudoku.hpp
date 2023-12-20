#pragma once
#include <iostream>
using namespace std;

class Sudoku {
    int table[9][9];
    bool findEmptyCell(int& row, int& col) const;

public:
    Sudoku();
    void print() const;
    bool isValidMove(int row, int col, int num) const;
    bool solve();
};
