//
// Created by Fatema Kapadia on 05/12/2025.
//

#ifndef DAY4_H
#define DAY4_H
#include <string>
#include <vector>

#include "Day.h"

namespace AOC {
    class Day4 final : public Day {
    public:
        void solve() override;
    private:
        void parseLine(const std::string& line);
        int checkForSymbol(int x, int y, int numRows, int numColumns) const;
        std::vector<std::vector<char>> mat;
        std::vector<std::pair<int, int>> positions = {
            {0,1}, {0,-1}, {1, 0}, {-1,0},
            {1,1}, {1,-1}, {-1, 1}, {-1,-1},
        };
    };

}

#endif //DAY4_H
