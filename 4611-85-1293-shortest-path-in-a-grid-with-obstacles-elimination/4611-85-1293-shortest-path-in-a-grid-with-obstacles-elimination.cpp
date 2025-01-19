class Solution {
public:

    typedef std::vector<std::vector<int>> vii;
    typedef std::vector<int> vi;
    typedef std::pair<int,int> ii;

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        std::queue<std::tuple<int, int, int, int>> q;
        vii visited(n, vi(m, -1));
        q.push(std::make_tuple(0, 0, 0, 0));
        visited[0][0] = 0;

        while (!q.empty()) {
            int r, c, removed, steps;
            std::tie(r, c, removed, steps) = q.front();
            q.pop();

            if (r == n - 1 && c == m - 1)
                return steps;

        std::array<ii, 4> dir = {{{-1,0},{0,1},{0,-1},{1,0}}};
            for (const auto& [dr, dc] : dir) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
                    grid[nr][nc] + removed > k || visited[nr][nc] != - 1 && visited[nr][nc] <= removed + grid[nr][nc])
                    continue;
                auto nei = std::make_tuple(nr, nc, grid[nr][nc] + removed, steps + 1);
                q.push(nei);
                visited[nr][nc] = removed + grid[nr][nc];
            }
        }
        return -1;
    }
};