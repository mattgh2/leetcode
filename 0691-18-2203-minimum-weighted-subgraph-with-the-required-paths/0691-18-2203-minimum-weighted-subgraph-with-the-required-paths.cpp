class Solution {
public:
    typedef long long ll;
    typedef std::vector<std::vector<int>> vii;
    typedef std::pair<int, double> id;
    typedef std::pair<int, int> ii;

    auto dijkstra(std::vector<std::vector<ii>>& adj, int s)
        -> std::vector<double> {
        auto comp = [](const auto& p1, const auto& p2) -> bool {
            return std::get<1>(p1) > std::get<1>(p2);
        };
        int n = adj.size();
        std::vector<double> dist(adj.size(),
                                 std::numeric_limits<double>::infinity());
        std::vector<int> visited(n, 0);

        std::priority_queue<id, std::vector<id>, decltype(comp)> pq;

        dist[s] = 0;

        pq.push(std::make_pair(s, 0));

        while (!pq.empty()) {
            auto [v, d] = pq.top();
            pq.pop();
            if (d > dist[v]) {
                continue;
            }

            for (const auto& [u, w] : adj[v]) {
                long long new_dist = (long long)(d + w);
                if (new_dist < dist[u]) {
                    dist[u] = new_dist;
                    pq.push({u, new_dist});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        std::vector<std::vector<ii>> adj(n);
        std::vector<std::vector<ii>> inverted(n);
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], w = edge[2];
            adj[from].push_back({to, w});
            inverted[to].push_back({from, w});
        }

        auto da = dijkstra(adj, src1);
        auto db = dijkstra(adj, src2);
        auto dd = dijkstra(inverted, dest);

        const double inf = std::numeric_limits<double>::infinity();
        if (da[dest] == inf || db[dest] == inf)
            return -1;

        long long ans = std::numeric_limits<long long>::max();
        for (int i = 0; i < n; ++i) {
            if (da[i] == inf || db[i] == inf || dd[i] == inf)
                continue;
            ans = std::min(ans, (long long)(da[i] + db[i] + dd[i]));
        }
        return ans;
    }
};