class Solution {
public:
    typedef std::pair<int, int> ii;
    typedef std::pair<ii, int> iii;

    int trapRainWater(vector<vector<int>>& heightMap) {
        auto comp = [](const iii& a, const iii& b) -> bool {
            return a.second > b.second;
        };
        int n = heightMap.size(), m = heightMap[0].size();
        std::priority_queue<iii, std::vector<iii>, decltype(comp)> pq;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push({{i, j}, heightMap[i][j]});
                    heightMap[i][j] = -1;
                }
            }
        }
        int ans = 0;
        int max_height = -1;

        while (!pq.empty()) {
            auto [rc, h] = pq.top();
            pq.pop();
            auto [r, c] = rc;
            max_height = std::max(max_height, h);
            ans += max_height - h;

            std::array<ii, 4> nei = {
                {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}}};
            for (const auto& [nr, nc] : nei) {
                if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
                    heightMap[nr][nc] == -1)
                    continue;
                pq.push({{nr, nc}, heightMap[nr][nc]});
                heightMap[nr][nc] = -1;
            }
        }
        return ans;
    }
};