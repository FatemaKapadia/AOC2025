//
// Created by Fatema Kapadia on 02/12/2025.
//

#ifndef DAY1_H
#define DAY1_H
#include <string>

#include "Day.h"

namespace AOC {
    class Day1 final : public Day {
    private:
        int parseLine(const std::string& line);
    public:
        void solve() override;
    };
}



#endif //DAY1_H
