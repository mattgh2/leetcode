#include <unordered_set>
#include <vector>
#include <iostream>
#include <array>
#include <iomanip>
class Solution {
public:
    typedef std::vector<int> vi;
    typedef std::pair<int,int> ii;
    typedef std::vector<std::vector<int>> vii;

    template <typename hash_function>
    using hs = std::unordered_set<ii, hash_function>;

    struct pair_hash {
        template <typename T1, typename T2>
            std::size_t operator()(const std::pair<T1, T2>& p) const {
                std::size_t h1 = std::hash<T1>{}(p.first);
                std::size_t h2 = std::hash<T2>{}(p.second);
                return h1 ^ (h2 << 1);
            }
    };

public:
    auto check_bounds(int row, int col, vii& heights) -> bool {
        return ((row >= 0 && row < heights.size()) && (col >= 0 && col < heights[0].size()));
    }

    vii pacificAtlantic(vii &heights) {

        vii results;

        hs<pair_hash> pacific;
        hs<pair_hash> atlantic;

        auto dfs = [&](auto &ff, int row, int col, hs<pair_hash>& ocean, int prev_size) {
            static std::array<ii, 4> d = {{{1,0},{-1,0},{0,-1},{0,1}}};
            if ((check_bounds(row,col, heights) == false) || heights[row][col] < prev_size || ocean.find(std::make_pair(row,col)) != ocean.end()) return;

            ocean.insert(std::make_pair(row,col));

            // Dfs on neighbors
            for (const auto & dir : d) {
                int new_row = row + dir.first, new_col = col + dir.second;
                ff(ff,new_row, new_col, ocean, heights[row][col]);
            }
        };

        for (size_t i = 0; i < heights[0].size();++i) {
            dfs(dfs,0, i, pacific,heights[0][i]);
            dfs(dfs,heights.size() - 1, i,atlantic, heights[heights.size() -1][i]);
        }

        for (size_t i = 0; i < heights.size(); ++i) {
            dfs(dfs, i, 0, pacific, heights[i][0]);
            dfs(dfs, i, heights[0].size() - 1, atlantic, heights[i][heights[0].size() - 1]);
        }


        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); ++j) {
                if (pacific.find({i,j}) != pacific.end() && atlantic.find({i,j}) != atlantic.end()) {
                    results.push_back({i,j});
                }
            }
        }
        return results;
    }
};

int main(int argc, char **argv){

    
    double num = 1e9;


    return 0;
}
