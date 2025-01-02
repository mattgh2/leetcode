#include <vector>
#include <array>
#include <queue>
#include <iostream>
#include <chrono>
#include <unordered_set>
class Solution {
public:
    typedef std::vector<std::vector<int>> vii;
    typedef std::pair<int,int> ii;

        struct hash_function {
            std::size_t operator()(const auto &p) const {
                std::size_t h1 = std::hash<decltype(p.first)>{}(p.first);
                std::size_t h2 = std::hash<decltype(p.second)>{}(p.second);
                return h1 ^ (h2 << 1);
            }
        };

    auto check_bounds(int row, int col, const vii &grid) -> bool {
        return ((row >= 0 && row < static_cast<int>(grid.size())) && (col >= 0 && col < static_cast<int>(grid[0].size())));
    }
    int orangesRotting(vii &grid) {

        std::queue<ii> q;
        size_t oranges = 0;
        std::unordered_set<ii, hash_function> visited;

        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) ++oranges;
                if (grid[i][j] == 2) {
                    q.push(std::make_pair(i,j));
                    visited.emplace(i,j);
                }
            }
        }

        std::array<ii, 4> d = {{{0,1},{0,-1},{1,0},{-1,0}}};
        int time = 0;

        while (!q.empty() && oranges > 0) {
            int size = q.size();
            for (size_t i = 0; i < size; ++i) {
                ii pair = q.front(); q.pop();
                for (const auto & dir : d) {
                    int new_row = pair.first + dir.first, new_col = pair.second + dir.second;
                    if (check_bounds(new_row, new_col, grid) && visited.find({new_row,new_col}) == visited.end()) {
                        if (grid[new_row][new_col] == 1) {
                            --oranges;
                            grid[new_row][new_col] = 2;
                            q.push(std::make_pair(new_row, new_col));
                            visited.emplace(new_row,new_col);
                        }
                    }
                }
            }

            ++time;
        }
        return oranges > 0 ? -1 : time;
    }
};
int main (){

    Solution solution;
    Solution::vii grid = {
        {2, 1, 1},
        {1, 1, 1},
        {0, 1, 2}
    };
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << solution.orangesRotting(grid);
    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = t2 - t1;

    std::cout << "\n runtime in m/s: " << duration.count() << '\n';

    std::cout << '\n';
}
