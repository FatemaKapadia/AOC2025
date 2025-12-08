//
// Created by Fatema Kapadia on 07/12/2025.
//

#ifndef DAY6_H
#define DAY6_H
#include <string>
#include <vector>

#include "Day.h"


namespace AOC {
    class Day6 final: public Day {
    public:
        void solve() override;
    private:
    std::vector<char> parseOperators(const std::string& line);
    std::vector<int> parseLine(const std::string& line);
    };
}



#endif //DAY6_H
