//
// Created by Fatema Kapadia on 03/12/2025.
//

#include "Day3.h"

#include <algorithm>
#include <iostream>
#include <ranges>

#include "utils.h"

namespace AOC {
    std::pair<int,int> getLargest(const std::vector<int>& arr, const int begin, const int end) {\
        std::pair<int,int> ret;
        int ans=0, index=0;
        for (int i=begin; i<=end; i++) {
            const int num = arr[i];
            if (num>ans) {
                ans = num;
                index = i;
            }
        }
        return std::make_pair(ans, index);
    }

void Day3::solve() {
        std::vector<std::string> lines = readFromFile("input3.1.txt");
        long long ans = 0;
        for (const auto& line : lines) {
            std::vector<int> arr = parseLineToIntegers(line);
            int largestIndex = -1;
            std::vector<int> currAns (12, 0);
            for (int i=12 ; i>0 ; i-- ) {
                const auto& x = getLargest(arr, largestIndex+1, arr.size()-i);
                largestIndex = x.second;
                currAns[12-i] = x.first;
            }

            for (auto i: currAns) std::cout << i << " ";
            std::cout << std::endl;

            long long curr = 0;
            for (int & currAn : currAns) {
                curr = curr*10ll + currAn*1ll;
            }
            std::cout << "Current number: " << curr << std::endl;
            ans += curr;
            std::cout << ans << std::endl;
        }
        std::cout << ans << std::endl;
    }
}