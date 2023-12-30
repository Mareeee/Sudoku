#ifndef SUDOKU_GENERATOR_HPP
#define SUDOKU_GENERATOR_HPP

#include "Sudoku.hpp"
using namespace std;

class SudokuGenerator {
public:
    void shuffleRows(Sudoku9& sudoku) const;
    void shuffleCols(Sudoku9& sudoku) const;
    void removeNumbers(Sudoku9& sudoku, int numToRemove) const;
    void removeExcess(Sudoku9& sudoku) const;
    Sudoku9 generateRandomSudoku(int numToRemove) const;
    int getGoodMoves(const Sudoku9& sudoku);
    int getBadMoves(const Sudoku9& sudoku);
    bool isFilled(const Sudoku9& sudoku);
};
#endif
