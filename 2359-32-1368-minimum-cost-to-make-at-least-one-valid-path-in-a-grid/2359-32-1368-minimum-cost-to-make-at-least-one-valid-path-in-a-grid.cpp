class Solution {
public:
    typedef std::pair<int, int> ii;
    typedef std::pair<ii, int> iii;
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto in_bounds = [&grid, n, m](int i, int j) -> bool {
            return (i >= 0 && j >= 0 && i < n && j < m);
        };
        std::vector<std::vector<int>> min_cost(
            n, std::vector<int>(m, std::numeric_limits<int>::max()));

        std::deque<iii> q;
        q.push_front({{0, 0}, 0});
        min_cost[0][0] = 0;

        std::array<ii, 4> directions = {{{0,1}, {0,-1}, {1,0}, {-1,0}}};
        while (!q.empty()) {
            auto [rc, cost] = q.front();
            q.pop_front();
            auto [r, c] = rc;
            if (r == n - 1 && c == m - 1)
                return cost;

            for (int i = 0; i < 4; ++i) {
                auto [dr, dc] = directions[i];
                int nr = r + dr, nc = c + dc;
                int cst = (i + 1 == grid[r][c]) ? cost : cost + 1;

                if (!in_bounds(nr, nc))
                    continue;
                if (cst >= min_cost[nr][nc])
                    continue;

                min_cost[nr][nc] = cst;

                if (i + 1 == grid[r][c]) {
                    q.push_front({{nr, nc}, cst});
                } else {
                    q.push_back({{nr, nc}, cst});
                }
            }
        }

        return -1;
    }
};