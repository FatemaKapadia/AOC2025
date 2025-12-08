//
// Created by Fatema Kapadia on 02/12/2025.
//


#include <fstream>

#include "utils.h"

#include <iostream>
#include <bits/regex_constants.h>

namespace AOC {
    std::vector<std::string> readFromFile(const std::string& filename) {
        std::ifstream input(filename);
        std::string line;
        std::vector<std::string> ret;

        if (input.fail()) {
            std::cout << "Could not open file " << filename << std::endl;
        }

        while (std::getline(input, line)) {
            ret.push_back(line);
        }
        return ret;
    }

}
