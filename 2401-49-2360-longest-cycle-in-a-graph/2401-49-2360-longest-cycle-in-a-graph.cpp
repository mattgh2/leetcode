class Solution {
public:
    std::vector<int> visited;
    std::vector<int> in;

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        in = std::vector<int>(n);
        visited = std::vector<int>(n);

        for (int i = 0; i < n; ++i) {
            if (edges[i] == -1)
                continue;

            ++in[edges[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0 && !visited[i]) {

                visited[i] = 1;
                int next = edges[i];

                while (next != -1 && --in[next] == 0) {
                    visited[next] = 1;
                    next = edges[next];
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int longest = 1;
            if (visited[i]) {
                continue;
            }
            visited[i] = 1;
            int next = edges[i];

            while (next != i && next != -1) {
                ++longest;
                visited[next] = 1;
                next = edges[next];
            }
            ans = std::max(ans, longest);
        }

        return ans;
    }
};