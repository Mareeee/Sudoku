#ifndef GAME_HPP
#define GAME_HPP

#include "SudokuGenerator.hpp"
#include "File.hpp"
#include "Sudoku.hpp"
#include <string>

class Game : public SudokuGenerator, public File {
    int gamesPlayed;
    string filepath;
    Sudoku9 sudoku;

public:
    Game(string filepath);
    void generateSudoku(int numToRemove);
    void printSudoku();
    void printStats();
    void solveSudoku();
};
#endif
