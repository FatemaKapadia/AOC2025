//
// Created by Fatema Kapadia on 08/12/2025.
//

#include "Day7.h"

#include <format>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include "utils.h"

namespace AOC {
    void Day7::convertToMatrix(const std::vector<std::string>& lines) {
        for (const auto& line : lines) {
            std::vector<char> currRow;
            for (const auto& c : line) {
                currRow.push_back(c);
            }
            matrix.push_back(currRow);
        }
        numRows = matrix.size();
        numCols = matrix[0].size();
    }

    bool Day7::isValid(const int x, const int y) const {
        if (x<0 || y<0)
            return false;
        if (x>=numRows || y>=numCols)
            return false;
        return true;
    }

    long long Day7::dfs(int x, int y, std::vector<std::vector<long long>>& seen) {
        if (!isValid(x, y))
            return 0;
        if (seen[x][y] != -1) {
            return seen[x][y];
        }

        if (isValid(x+1, y)) {
            if (matrix[x+1][y] == '.') {
               seen[x][y] = dfs(x+1, y, seen);
            }
            else if (matrix[x+1][y] == '^') {
               seen[x][y] = dfs(x+1, y-1, seen) + dfs(x+1, y+1, seen);
            }
        } else {
            seen[x][y] = 1;
        }
        return seen[x][y];
    }
    void Day7::solve() {
        std::vector<std::string> lines = readFromFile("input7.txt");
        std::priority_queue<CoordRank, std::vector<CoordRank>, std::greater<CoordRank>> pq;
        std::map<int, int> cnt;
        convertToMatrix(lines);
        std::vector<std::vector<long long>> seen(numRows, std::vector<long long>(numCols, -1));
        long long ans=0;
        for (int i=0 ; i<matrix[0].size() ; i++) {
            if (matrix[0][i]=='S') {
               ans = dfs(0, i, seen);
            }
        }
        // int ans = 0;
        // while (!pq.empty()) {
        //     CoordRank curr = pq.top();
        //     pq.pop();
        //
        //     if (seen.contains(curr))
        //         continue;
        //
        //     cnt[curr.pos]++;
        //     seen.insert(curr);
        //     if (!isValid(curr.x+1, curr.y))
        //         continue;
        //     if (matrix[curr.x+1][curr.y] == '.') {
        //         pq.emplace(curr.x+1, curr.y, curr.pos+1);
        //     }
        //     else if (matrix[curr.x+1][curr.y] == '^') {
        //         ans++;
        //         pq.emplace(curr.x+1, curr.y-1, curr.pos+1);
        //         pq.emplace(curr.x+1, curr.y+1, curr.pos+1);
        //     }
        // }

        std::cout  << " " << ans << std::endl;
    }
}
