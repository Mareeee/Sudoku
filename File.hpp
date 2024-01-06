#ifndef FILE_HPP
#define FILE_HPP

#include "Sudoku.hpp"
#include <string>

/**
 * @brief Handles file operations related to Sudoku.
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
    *@brief Clears the gamesPlayed configuration by setting it to 0.
    */
    void clearConfig() const;

    /**
     * @brief Loads the Sudoku game from the Sudoku data file.
     * skipLine Skips a line every 3 iterations, since the board consists of rows without numbers (-+---+-)
     *
     * whitespacesBefore Skips first 8 whitespaces, since the board is stored with 8 prefix spaces (for beauty reasons)
     * whitespacesInside Skips empty positions when reading from a file, due to the reason that empty places
     *  were not allowed to be represented by 0s and -1s
     *
     * @return The Sudoku9 object representing the loaded game state.
     */
    Sudoku9 loadSudoku();

    /**
     * @brief Loads the gamesPlayed configuration from the configuration file.
     * @return The number of games played.
     */
    int loadConfig();
};
#endif