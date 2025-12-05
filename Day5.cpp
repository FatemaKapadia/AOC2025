//
// Created by Fatema Kapadia on 05/12/2025.
//

#include "Day5.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <bits/ostream.tcc>

#include "utils.h"

namespace AOC {
    std::pair<long,long> parseRange(const std::string& rangeStr) {
        size_t dashPos = rangeStr.find('-');
        try {
            long long start = std::stoll(rangeStr.substr(0, dashPos));
            long long  end = std::stoll(rangeStr.substr(dashPos + 1));
            return std::make_pair(start, end);
        }
        catch (std::exception& e){
            std::cerr << e.what() << std::endl;
            std::cout << rangeStr << " " << dashPos << std::endl;
            throw std::invalid_argument("Invalid Range");
        }
    }

    long long parseIngredientId(const std::string& ingredientStr) {
        try {
            const long long id = std::stoll(ingredientStr);
            std::cout << ingredientStr << " " << id << std::endl;
            return id;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            std::cout << ingredientStr << std::endl;
            throw std::invalid_argument("Invalid Ingredient");
        }
    }

    void Day5::addToRanges(const std::pair<long, long>& range) {
        freshRanges.push_back(range);
    }


    int Day5::isPresent(const long long ingredient) const {
        for (const auto&[beginId, endId]: freshRanges) {
            if (ingredient >= beginId && ingredient <= endId) {
                // std::cout << ingredient << " " << beginId << " " << endId << std::endl;
                return 1;
            }
        }
        return 0;
    }

    long long Day5::countAllFreshIngredients() const {
        long long ans = 0;
        for (const auto&[beginId, endId]: freshRanges) {
            ans += (endId - beginId + 1);
        }
        return ans;
    }

    void Day5::displayRanges() const {
        for (const auto&[beginId, endId]: freshRanges) {
            std::cout << beginId << " " << endId << std::endl;
        }
    }

    void Day5::mergeRanges() {
        std::ranges::sort(freshRanges);
        std::cout << freshRanges.size() << std::endl;
        displayRanges();
        std::vector<std::pair<long, long>> mergedRanges;
        mergedRanges.push_back(freshRanges.front());
        for (int i=1 ; i<freshRanges.size() ; i++) {
            auto& lastRange = mergedRanges.back();
            if (lastRange.second>=freshRanges[i].first-1) {
                lastRange.second = std::max(freshRanges[i].second, lastRange.second);
            } else {
                mergedRanges.push_back(freshRanges[i]);
            }
        }
        freshRanges = mergedRanges;

        std::cout << freshRanges.size() << std::endl;
        displayRanges();
    }

    void Day5::solve() {
        // Implementation for Day5's solve method goes here.
        std::vector<std::string> lines = readFromFile("input5.txt");
        std::vector<long long> ingredients;
        for (const auto& line : lines) {
            if (line.find('-')!=std::string::npos) {
                addToRanges(parseRange(line));
            }
            else if (line.empty())
                continue;
            else {
                ingredients.push_back(parseIngredientId(line));
            }
        }

        mergeRanges();
        int ans=0;
        std::cout << ingredients.size() << std::endl;
        for (const auto& ingredient: ingredients) {

            ans += isPresent(ingredient);
        }

        std::cout << countAllFreshIngredients() << std::endl;
    }
}
