#ifndef GAME_HPP
#define GAME_HPP

#include "SudokuGenerator.hpp"
#include "File.hpp"
#include <string>

/**
 * @brief Represents the Sudoku game, derived from SudokuGenerator.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

class Game : public SudokuGenerator {
    File fileHandler;   /**< File handler for managing file operations. */
    Sudoku9 sudoku;     /**< Sudoku board for the game. */
    int gamesPlayed;    /**< Number of games played. */

public:
    /**
     * @brief Constructor for the Game class.
     * @param sudokuFilepath The filepath for the Sudoku data file.
     * @param configFilepath The filepath for the configuration file.
     */
    Game(string sudokuFilepath, string configFilepath);
    
    /**
     * @brief Displays the main menu and handles user input for various game actions.
     */
    void menu();

    /**
     * @brief Resets the current Sudoku game and saves the state.
     */
    void resetSudoku();

    /**
     * @brief Generates a new Sudoku game with a specified number of cells removed.
     * @param numToRemove The number of cells to be removed from the generated Sudoku.
     */
    void generateSudoku(int numToRemove);

     /**
      * @brief Prints the current state of the Sudoku game.
      */
    void printSudoku();

    /**
     * @brief Prints statistics about the current game, including the number of games played,
     * good moves, and bad moves (if the Sudoku is completed).
     */
    void printStats();

    /**
     * @brief Solves the current Sudoku puzzle.
     */
    void solveSudoku();

    /**
     * @brief Resets the game counter by clearing the configuration file.
     * @brief It also asks for the user confirmation when doing so.
     */
    void resetConfig();

    /**
     * @brief Prints out definitions of menu options
    */
    void help();
};
#endif
