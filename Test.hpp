#ifndef TEST_HPP
#define TEST_HPP

#include "File.hpp"
using namespace std;

class Test {
	File fileHandler;
	Sudoku9 sudoku;
	int gamesPlayed;
public:
	Test(string sudokuFilepath, string configFilepath);
	void runAll();
};
#endif