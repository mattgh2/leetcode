class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));

        std::queue<std::tuple<int, int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j]) {
                    q.push(std::make_tuple(i, j, 0));
                }
            }
        }
        while (!q.empty()) {
            int r, c, dist;
            std::tie(r, c, dist) = q.front();
            q.pop();

            std::array<std::pair<int, int>, 4> nei = {
                {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};
            for (const auto& [dr, dc] : nei) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                    continue;
                }

                if (ans[nr][nc] == 0 && isWater[nr][nc] != 1) {
                    q.push(std::make_tuple(nr, nc, dist + 1));
                    ans[nr][nc] = dist + 1;
                }
            }
        }

        return ans;
    }
};