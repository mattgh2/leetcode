class Solution {
public:
    typedef std::pair<int, int> ii;
    typedef std::pair<ii, int> iii;
    typedef std::vector<int> vi;
    typedef std::vector<vi> vii;

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto in_bounds = [&grid, m, n](int i, int j) -> bool {
            return (i >= 0 && j >= 0 && i < n && j < m);
        };

        vii distance(n, vi(m, std::numeric_limits<int>::max()));
        std::deque<iii> q;

        q.push_front({{0, 0}, 0});
        distance[0][0] = 0;

        std::array<ii, 4> directions = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

        while (!q.empty()) {
            auto [rc, d] = q.front();
            q.pop_front();
            auto [r, c] = rc;

            if (r == n - 1 && c == m - 1)
                return d;

            for (int i = 0; i < 4; ++i) {
                auto [dr, dc] = directions[i];
                int nr = r + dr, nc = c + dc;

                if (!in_bounds(nr, nc))
                    continue;
                int nd = (grid[nr][nc]) ? d + 1 : d;

                if (nd >= distance[nr][nc])
                    continue;

                distance[nr][nc] = nd;

                if (grid[nr][nc] == 1) {
                    q.push_back({{nr, nc}, d + 1});
                } else {
                    q.push_front({{nr, nc}, d});
                }
            }
        }
        return -1;
    }
};