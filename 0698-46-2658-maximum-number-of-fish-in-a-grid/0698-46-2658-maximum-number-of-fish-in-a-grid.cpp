class Solution {
public:
    auto dfs(std::vector<std::vector<int>>& grid, int r, int c) -> int {
        int m = grid[0].size(), n = grid.size();
        int ans = grid[r][c];

        grid[r][c] = 0;

        const static std::array<std::pair<int, int>, 4> directions = {
            {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

        for (const auto& [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }
            if (grid[nr][nc] != 0)
                ans += dfs(grid, nr, nc);
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        std::vector<std::vector<int>> visited(n, std::vector<int>(m));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    ans = std::max(dfs(grid, i, j), ans);
                }
            }
        }
        return ans;
    }
};