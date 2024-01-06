/**
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include "Game.hpp"
#include "Test.hpp"

/**
 * @brief The main entry point for the program.
 *
 * This function checks the command-line arguments and initializes either
 *  a Test or Game object based on the presence of the "TEST" argument.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of C-style strings representing the command-line arguments.
 * @return An integer indicating the exit status of the program.
 */
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