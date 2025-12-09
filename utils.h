//
// Created by Fatema Kapadia on 03/12/2025.
//
#include <iostream>
#include <string>
#include <vector>
#ifndef UTILS_H
#define UTILS_H
namespace AOC {
    std::vector<std::string> readFromFile(const std::string& filename);

    template<typename T>
    void display(std::vector<T> vec) {
        for (auto& x: vec) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> parseLineToIntegers(const std::string& line);
}
#endif //UTILS_H
