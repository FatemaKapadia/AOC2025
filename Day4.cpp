//
// Created by Fatema Kapadia on 05/12/2025.
//

#include "Day4.h"

#include <iostream>
#include <bits/ostream.tcc>

#include "utils.h"

namespace AOC {
    void Day4::parseLine(const std::string& line) {
        std::vector<char> row;
        for (const char c: line) {
            row.push_back(c);
        }
        mat.push_back(row);
    }

    int Day4::checkForSymbol(const int x, const int y, int numRows, int numColumns) const {
        if (x<0 || y<0) return 0;
        if (x>=numRows || y>=numColumns) return 0;
        if (mat[x][y] == '@') {
            std::cout << x << " " << y << std::endl;
            return 1;
        }
        return 0;
    }

    void Day4::solve() {
        std::vector<std::string> lines = readFromFile("input4.txt");
        for (const auto& line : lines) {
            parseLine(line);
        }

        int ans = 0;
        bool wasAbleToRemove = true;
        while (wasAbleToRemove) {
            wasAbleToRemove = false;
            for (int i=0 ; i<mat.size() ; i++) {
                for (int j=0 ; j<mat[i].size() ; j++) {
                    if (mat[i][j] == '.') continue;
                    int count = 0;
                    for (const auto& pos : positions) {
                        const int newX = i + pos.first;
                        const int newY = j + pos.second;
                        count += checkForSymbol(newX, newY, mat.size(), mat[i].size());
                    }
                    if (count < 4) {
                        mat[i][j] = '.';
                        wasAbleToRemove = true;
                        ans++;
                    }
                }
            }
        }
        std::cout << ans << std::endl;
    }

}
