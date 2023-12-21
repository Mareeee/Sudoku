#ifndef SUDOKU_GENERATOR_HPP
#define SUDOKU_GENERATOR_HPP

#include "Sudoku.hpp"
#include <string>
using namespace std;

class SudokuGenerator : public Sudoku9 {
    int goodMoves;
    int badMoves;

public:
    SudokuGenerator();
    void shuffleRows(Sudoku9& sudoku) const;
    void shuffleCols(Sudoku9& sudoku) const;
    void removeNumbers(Sudoku9& sudoku, int numToRemove) const;
    Sudoku9 generateRandomSudoku(int numToRemove) const;
    int getGoodMoves(const Sudoku9& sudoku);
    int getBadMoves(const Sudoku9& sudoku);
};
#endif
