/**
 * @brief Handles file operations for saving and loading Sudoku games.
 *
 * @author Marko Cvijanović
 * @date 31.12.2023.
 */

#include "File.hpp"
#include <fstream>

File::File(const string& newSudokuFilepath, const string& newConfigFilepath) : sudokuFilepath(newSudokuFilepath), configFilepath(newConfigFilepath) {}

/**
 * @brief Writes data of type T to a file.
 * @tparam T Type of data to be written.
 * @param filepath The filepath of the target file.
 * @param data The data to be written.
 */
template <typename T>
void writeToFile(const string& filepath, const T& data) {
    ofstream file(filepath);
    if (file.is_open()) {
        file << data;
    }
    file.close();
}

void File::save(const Sudoku9& sudoku, int gamesPlayed) const {
    writeToFile(sudokuFilepath, sudoku);
    writeToFile(configFilepath, gamesPlayed);
}

void File::clearConfig() const {
    writeToFile(configFilepath, 0);
}

Sudoku9 File::loadSudoku() {
    Sudoku9 sudoku;

    ifstream file(sudokuFilepath);
    if (file.is_open()) {
        string line;
        getline(file, line);

        int skipLine = 3;
        int i = 0;
        while (!file.eof()) {
            getline(file, line);
            if (skipLine >= 3) {
                skipLine = 0;
                continue;
            }

            ++skipLine;
            int j = 0;
            int whitespacesBefore = 0;
            int whitespacesInside = 0;
            for (char c : line) {
                if (whitespacesBefore < 8) {
                    ++whitespacesBefore;
                    continue;
                }
                if (c >= '0' && c <= '9') {
                    sudoku.setCellValue(i, j, c - '0');
                    ++j;
                }
                else if (c == '|') {
                    whitespacesInside = 0;
                    continue;
                }
                else if (c == ' ' && whitespacesInside % 2 == 1) {
                    sudoku.setCellValue(i, j, 0);
                    ++j;
                }
                ++whitespacesInside;
            }
            ++i;
        }

        file.close();
    }
    return sudoku;
}

int File::loadConfig() {
    int gamesPlayed = 0;

    ifstream file(configFilepath);
    if (file.is_open()) {
        string line;
        getline(file, line);
        gamesPlayed = stoi(line);
        file.close();
    }
    return gamesPlayed;
}