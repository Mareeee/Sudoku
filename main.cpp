#include "Game.hpp"
#include "Test.hpp"

int main(int argc, char* argv[]) {
	if (string(argv[3]) == "TEST") {
		Test test(argv[1], argv[2]);
		test.runAll();
	}
	else {
		Game game(argv[1], argv[2]);
		game.menu();
	}
}