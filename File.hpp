#ifndef FILE_HPP
#define FILE_HPP

#include "Sudoku.hpp"
#include <string>
using namespace std;

class File : public Sudoku {
public:
    void saveSudoku(const Sudoku& sudoku, const string& filename);
    Sudoku loadSudoku(const string& filename);
};
#endif