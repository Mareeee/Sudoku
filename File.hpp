#ifndef FILE_HPP
#define FILE_HPP

#include "Sudoku.hpp"
#include <string>
using namespace std;

class File : public Sudoku9 {
public:
    void saveSudoku(const Sudoku9& sudoku, const string& filename);
    Sudoku9 loadSudoku(const string& filename);
};
#endif