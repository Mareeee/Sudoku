#ifndef GAME_HPP
#define GAME_HPP

#include "SudokuGenerator.hpp"
#include "File.hpp"
#include <string>

/**
 * @brief Represents the Sudoku game, derived from SudokuGenerator.
 * @details The Game class manages the game state, including the Sudoku board,
 *  game statistics, and file operations.
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
     * @brief Displays the looping main menu for the game.
     */
    void menu();

    /**
     * @brief Resets the Sudoku board.
     */
    void resetSudoku();

    /**
     * @brief Generates a new Sudoku puzzle.
     * @param numToRemove Number of cells to remove from the generated puzzle.
     */
    void generateSudoku(int numToRemove);

    /**
     * @brief Prints the current Sudoku board.
     */
    void printSudoku();

    /**
     * @brief Prints game statistics.
     */
    void printStats();

    /**
     * @brief Solves the current Sudoku puzzle.
     */
    void solveSudoku();

    /**
     * @brief Resets game configuration.
     */
    void resetConfig();
};
#endif
