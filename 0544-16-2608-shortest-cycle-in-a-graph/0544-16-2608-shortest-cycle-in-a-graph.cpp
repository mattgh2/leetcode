class Solution {
public:
    typedef std::vector<std::vector<int>> vii;

    vii adj;
    std::bitset<1001> visited;

    int bfs(int source, int start, int removed, vii& adj) {
        std::queue<std::tuple<int, int, int>> q;
        q.push({source, 1, source});
        visited[source] = 1;

        int dist = 0;

        while (!q.empty()) {
            int c, d, from;
            std::tie(c, d, from) = q.front();
            q.pop();

            dist = d;

            for (const auto& u : adj[c]) {
                if (c != start && u == removed) {
                    return dist + 1;
                }
                if (u != from && visited[u] == 0 && u != removed) {
                    q.push({u, d + 1, c});
                    visited[u] = 1;
                }
            }
        }
        return -1;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {

        // For every edge in the graph, run a shortest path from a_i to b_i
        // without including the direct edge
        // If such a path exists, then it is a cycle with distance D.
        // If no such path exists, then there is no cycle.

        adj = vii(n);

        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1];

            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        int ans = INT_MAX;
        bool found_cycle = false;
        for (const auto& edge : edges) {
            visited ^= visited;
            int a = edge[0], b = edge[1];

            int count = bfs(a, a, b, adj);
            if (count == -1)
                continue;
            ans = std::min(ans, count);
            found_cycle = true;
        }

        return found_cycle ? ans : -1;
    }
};