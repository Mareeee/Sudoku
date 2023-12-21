#ifndef GAME_HPP
#define GAME_HPP

#include "SudokuGenerator.hpp"
#include "File.hpp"
#include <string>
using namespace std;

class Game : public SudokuGenerator, public File {
public:
	void generateSudoku(string filepath, int numToRemove);
	void printSudoku(string filepath);
	void solveSudoku(string filepath);
};
#endif
