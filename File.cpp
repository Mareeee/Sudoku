#include "File.hpp"
#include "Sudoku.hpp"
#include <fstream>

void File::saveSudoku(const Sudoku9& sudoku, const string& filepath) {
    ofstream file(filepath);
    if (file.is_open()) {
        file << "----------BOARD----------" << endl;
        for (int i = 0; i < 9; ++i) {
            if (i % 3 == 0 && i != 0) {
                file << "--------+-------+--------" << endl;
            }

            file << "| ";

            for (int j = 0; j < 9; ++j) {
                if (j % 3 == 0 && j != 0) {
                    file << "| ";
                }

                if (sudoku.getCellValue(i, j) == 0) {
                    file << "0 ";
                }
                else {
                    file << sudoku.getCellValue(i, j) << " ";
                }

                if (j == 8) {
                    file << "|";
                }
            }
            file << endl;
        }
        file << "-------------------------";
        file.close();
    }
}

Sudoku9 File::loadSudoku(const string& filepath) {
    Sudoku9 sudoku;

    ifstream file(filepath);
    if (file.is_open()) {
        string line;
        getline(file, line);
        
        int skipLine = 0;
        int i = 0;
        while (!file.eof()) {
            getline(file, line);
            if (skipLine >= 3) {
                skipLine = 0;
                continue;
            }

            ++skipLine;
            int j = 0;
            for (char c : line) {
                if (c >= '0' and c <= '9') {
                    sudoku.setCellValue(i, j, c - '0');
                    ++j;
                }
            }
            ++i;
        }

        file.close();
    }
    return sudoku;
}