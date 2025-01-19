class Solution {
public:
    typedef std::pair<int,int> ii;
    typedef std::vector<int> vi;
    typedef std::vector<std::vector<int>> vii;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size(), m = grid[0].size();

        vii visited(n, vi(m, 0));
        std::queue<std::tuple<int,int,int>> q;
        q.push(std::make_tuple(0,0,1));
        visited[0][0] = 1;

        while (!q.empty()) {
            int r,c,distance ;
            std::tie(r,c,distance) = q.front(); q.pop();
            if (r == n - 1 && c == m - 1) return distance;

            std::array<std::pair<int, int>, 8> directions = {{ {-1, 0}, {1, 0}, {0, -1}, {0, 1},  {-1, -1}, {-1, 1},   {1, -1},   {1, 1}}};

            for (const auto &[dr,dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc] == 1 || grid[nr][nc] == 1) continue;

                visited[nr][nc] = true;

                q.push(std::make_tuple(nr,nc,distance + 1));
            }
        }
        return -1;
        
        
    }
};