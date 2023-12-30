#include "Game.hpp"
#include "Sudoku.hpp"
#include "Test.hpp"

// Run command: C:\Users\Marko\OneDrive\Desktop\OOP2\Projektni_zadatak\Sudoku\x64\Debug\Sudoku.exe "Sudoku.txt"
int main(int argc, char* argv[]) {
	if (argv[3] == "TEST") {
		Test test(argv[1], argv[2]);
		test.runAll();
	}
	//else {
		Game game("Sudoku.txt", "Config.txt");
		game.menu();
	//}
}