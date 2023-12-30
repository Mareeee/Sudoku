#ifndef GAME_HPP
#define GAME_HPP

#include "SudokuGenerator.hpp"
#include "File.hpp"
#include <string>

class Game : public SudokuGenerator {
    File fileHandler;
    Sudoku9 sudoku;
    int gamesPlayed;

public:
    Game(string sudokuFilepath, string configFilepath);
    void menu();
    void resetSudoku();
    void generateSudoku(int numToRemove);
    void printSudoku();
    void printStats();
    void solveSudoku();
    void resetConfig();
};
#endif
