#ifndef TEST_HPP
#define TEST_HPP

#include "File.hpp"
#include "SudokuGenerator.hpp"
using namespace std;

class Test {
	File fileHandler;
	SudokuGenerator sudokuGenerator;
	Sudoku9 sudoku, emptySudoku;
	int gamesPlayed;
public:
	Test(const string sudokuFilepath, const string configFilepath);
	void runAll();
	bool autocompleteSudoku();
	bool faultySudoku();
	bool gameCounter();
	bool fileHandling();
	bool createRandomSudokuBoard();
};
#endif