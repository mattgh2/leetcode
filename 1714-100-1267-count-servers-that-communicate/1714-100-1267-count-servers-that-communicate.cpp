class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<int> mp(n + m); 
        std::vector<std::pair<int,int>> ones;

        int sz = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    ones.push_back({i,j});
                    ++mp[i], ++mp[j + n];
                }
            }
        }

        int ans = ones.size();
        for (int i = 0; i < ones.size(); ++i) {
            auto [row,col] = ones[i];
            if (mp[row] < 2 && mp[col + n] < 2) --ans;
        }
        return ans;
    }
};