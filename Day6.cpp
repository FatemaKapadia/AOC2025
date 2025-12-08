//
// Created by Fatema Kapadia on 07/12/2025.
//

#include "Day6.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <bits/regex_constants.h>

#include "utils.h"

namespace AOC {
    std::vector<int> Day6::parseLine(const std::string& line) {
        std::vector<int> result;
        std::stringstream ss(line);
        std::string num;

        while (ss>>num) {
            // std::cout << num << std::endl;
            result.push_back(std::stoi(num));
        }
        return result;
    }

    std::vector<char> Day6::parseOperators(const std::string& line) {
        std::vector<char> result;
        std::stringstream ss(line);
        std::string op;
        while (ss >> op) {
            // std::cout << op[0] << std::endl;
            result.push_back(op[0]);
        }
        return result;
    }
    void Day6::solve() {
        std::vector<std::string> lines = readFromFile("input6.txt");
        std::vector<std::vector<int>> mat;

        for (int i = 0 ; i < lines.size() - 1 ; i++) {
            auto listOfNumbers = parseLine(lines[i]);
            mat.push_back(listOfNumbers);
        }

        std::vector<char> operators = parseOperators(lines.back());

        for (int i=0 ; i<mat.size() ; i++) {
            display(mat[i]);
        }
        display(operators);
        std::vector<long long> results(operators.size());
        for (int j=0; j < results.size(); j++) {
            if (operators[j] == '+') {
                results[j] = 0;
            } else if (operators[j] == '*') {
                results[j] = 1;
            }
        }
        display(results);
        for (int i=0 ; i<mat.size() ; i++) {
            for (int j=0 ; j<mat[i].size() ; j++) {
                std::cout << mat[i][j] << " " << std::endl;
                display(results);
                if (operators[j] == '+') {
                    std::cout << " i am adding this" << std::endl;
                    results[j] += mat[i][j];
                }
                else if (operators[j] == '*') {
                    std::cout << " i am multiplying this" << std::endl;
                    results[j] *= mat[i][j];
                }
                display(results);
            }
        }

        long long ans = 0;

        for (auto& x: results) ans += x;

        std::cout << ans << std::endl;
    }

}
