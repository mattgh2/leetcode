class Solution {
public:
    typedef std::vector<std::vector<int>> vii;
    typedef std::pair<int, int> ii;

    const std::array<ii, 4> directions = {{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}};
    vii island_number;
    vii island_size;

    int dfs(int r, int c, vii& grid, int idx) {

        int count = 1;

        grid[r][c] = -idx;

        for (const auto& dir : directions) {
            auto [dr, dc] = dir;

            int nr = r + dr, nc = c + dc;

            if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid.size()) {
                continue;
            }
            if (grid[nr][nc] <= 0) {
                continue;
            }
            count += dfs(nr, nc, grid, idx);
        }
        island_number[r][c] = idx;

        return count;
    }
    void set_sizes(int r, int c, vii& grid, int size, int idx) {

        island_size[r][c] = size;
        grid[r][c] = INT_MIN;

        for (const auto& dir : directions) {
            auto [dr, dc] = dir;

            int nr = r + dr, nc = c + dc;

            if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid.size()) {
                continue;
            }
            if (grid[nr][nc] != -idx) {
                continue;
            }
            set_sizes(nr, nc, grid, size, idx);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        island_number = std::vector<std::vector<int>>(n, std::vector<int>(n));
        island_size = std::vector<std::vector<int>>(n, std::vector<int>(n));
        std::queue<ii> q;

        int count = 0, idx = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int count = dfs(i, j, grid, idx);
                    set_sizes(i, j, grid, count, idx++);
                } else if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        if (q.empty()) {
            return n * n;
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            std::unordered_set<int> seen;
            int res = 0;

            for (const auto& dir : directions) {

                auto [dr, dc] = dir;
                int nr = i + dr, nc = j + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= n ||
                    seen.find(island_number[nr][nc]) != seen.end())
                    continue;

                res += island_size[nr][nc];
                seen.insert(island_number[nr][nc]);
            }
            ans = std::max(ans, res);
        }

        return ans + 1;
    }
};
