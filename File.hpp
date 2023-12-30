#ifndef FILE_HPP
#define FILE_HPP

#include "Sudoku.hpp"
#include <string>
using namespace std;

class File {
    string sudokuFilepath;
    string configFilepath;
public:
    void setFilepath(const string& newSudokuFilepath, const string& newConfigFilepath);
    void save(const Sudoku9& sudoku, int gamesPlayed);
    void clearConfig();
    Sudoku9 loadSudoku();
    int loadConfig();
};
#endif