#ifndef FILE_HPP
#define FILE_HPP

#include "Sudoku.hpp"
#include <string>

/**
 * @brief Handles file operations related to Sudoku.
 * @details The File class provides functionality to save and load Sudoku data,
 * as well as manage configuration information.
 * 
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

class File {
    string sudokuFilepath; /**< Filepath for the Sudoku data file. */
    string configFilepath; /**< Filepath for the configuration file. */

public:
    /**
     * @brief Constructor for the File class.
     * @param newSudokuFilepath The filepath for the Sudoku data file.
     * @param newConfigFilepath The filepath for the configuration file.
     */
    File(const string& newSudokuFilepath, const string& newConfigFilepath);
    
    /**
     * @brief Saves Sudoku data and games played information to a file.
     * @param sudoku The Sudoku object to be saved.
     * @param gamesPlayed The number of games played to be saved.
     */
    void save(const Sudoku9& sudoku, int gamesPlayed) const;
    
    /**
     * @brief Clears the configuration file.
     */
    void clearConfig() const;

    /**
     * @brief Loads Sudoku data from the Sudoku data file.
     * @return Loaded Sudoku object.
     */
    Sudoku9 loadSudoku();

    /**
     * @brief Loads configuration data from the configuration file.
     * @return Number of games played loaded from the configuration.
     */
    int loadConfig();
};
#endif