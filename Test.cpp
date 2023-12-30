#include "Test.hpp"
using namespace std;

Test::Test(string sudokuFilepath, string configFilepath) {
	fileHandler.setFilepath(sudokuFilepath, configFilepath);
	sudoku = fileHandler.loadSudoku();
	gamesPlayed = fileHandler.loadConfig();
}

void Test::runAll()
{
	cout << "Running Test Cases..." << endl;
}
