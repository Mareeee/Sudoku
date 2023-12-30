#ifndef FILE_HPP
#define FILE_HPP

#include "Sudoku.hpp"
#include <string>
using namespace std;

class File {
    string sudokuFilepath;
    string configFilepath;
public:
    File(const string& newSudokuFilepath, const string& newConfigFilepath);
    void save(const Sudoku9& sudoku, int gamesPlayed) const;
    void clearConfig() const;
    Sudoku9 loadSudoku();
    int loadConfig();
};
#endif