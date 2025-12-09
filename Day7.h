//
// Created by Fatema Kapadia on 08/12/2025.
//

#ifndef DAY7_H
#define DAY7_H
#include <string>
#include <vector>

#include "Day.h"


namespace AOC {
    class Day7 final: public Day {
    public:
        void solve() override;
    private:
        std::vector<std::vector<char>> matrix;
        void convertToMatrix(const std::vector<std::string>& lines);
        long long dfs(int x, int y, std::vector<std::vector<long long>>& seen);
        class CoordRank {
            public:
            int x, y, pos;
            CoordRank(int x, int y, int pos) : x(x), y(y), pos(pos) {}

            bool operator<(const CoordRank& rhs) const {
                if (pos!=rhs.pos) {
                    return pos<rhs.pos;
                }
                if (x!=rhs.x) {
                    return x<rhs.x;
                }
                return y<rhs.y;
            }

            bool operator>(const CoordRank& rhs) const {
                return !(*this < rhs);
            }

            bool operator==(const CoordRank& rhs) const {
                return x==rhs.x && y==rhs.y;
            }
        };
        bool isValid(int x, int y) const;
        int numRows, numCols;
    };

}



#endif //DAY7_H
