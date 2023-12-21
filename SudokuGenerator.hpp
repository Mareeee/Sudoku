#ifndef SUDOKU_GENERATOR_HPP
#define SUDOKU_GENERATOR_HPP

#include "Sudoku.hpp"
#include <string>
using namespace std;

class SudokuGenerator : public Sudoku {
//void removeNumbers(Sudoku& sudoku) const;
public:
    //Sudoku generateRandomSudoku() const;
    void shuffleRows(Sudoku& sudoku) const;
    void shuffleCols(Sudoku& sudoku) const;
    void removeNumbers(Sudoku& sudoku, int numToRemove) const;
    Sudoku generateRandomSudoku(int numToRemove) const;
};
#endif
