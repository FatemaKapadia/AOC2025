//
// Created by Fatema Kapadia on 02/12/2025.
//

#include "Day1.h"

#include <fstream>
#include <iostream>
#include <filesystem>
#include "utils.h"

namespace AOC {
    void Day1::solve() {
        const auto lines = readFromFile("input1.1.txt");
        int curr = 50;
        int ans=0;
        for (const auto& line: lines) {
            std::cout << line << "\n";
            const int moves = parseLine(line);

            int passes = abs(moves/100);
            const int remMoves = moves%100;

            const int tmp = curr + remMoves;

            if (tmp <0 || tmp>100) {
                passes++;
            }
            std::cout << "tmp " << tmp << " passes " << passes << " remMoves " << remMoves << "\n";

            curr = (tmp+100)%100;

            if (curr == 0) {
                ans++;
            }
            ans += passes;
        }
        std::cout << ans << std::endl;
    }

    int Day1::parseLine(const std::string& line) {
        if (line[0]=='R') {
            return std::stoi(line.substr(1));
        } else if (line[0]=='L') {
            return -std::stoi(line.substr(1));
        }
        throw std::runtime_error("Something is wrong with your input");
    }
}
