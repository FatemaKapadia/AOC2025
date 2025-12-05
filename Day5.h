//
// Created by Fatema Kapadia on 05/12/2025.
//

#ifndef DAY5_H
#define DAY5_H
#include <utility>
#include <vector>

#include "Day.h"

namespace AOC {
    class Day5 final : public Day {
    public:
        void solve() override;
        private:
        std::vector<std::pair<long, long>> freshRanges;
        void addToRanges(const std::pair<long,long>& range);
        int isPresent(long long ingredient) const;
        void mergeRanges();
        void displayRanges() const;
        long long countAllFreshIngredients() const;
    };
}


#endif //DAY5_H
