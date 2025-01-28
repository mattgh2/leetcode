class TreeAncestor {

    int LOG;
    std::vector<std::vector<int>> up;
    std::vector<std::vector<int>> adj;
    std::vector<int> depths;

public:
    void get_depths(std::vector<std::vector<int>> &adj){


        std::queue<std::pair<int,int>> q;
        q.push({0,0});

        while (!q.empty()) {
            auto [v, d] = q.front();
            q.pop();

            depths[v] = d;

            for (const auto & u : adj[v]) {
               q.push({u, d + 1});
            }
        }
    }

    TreeAncestor(int n, vector<int>& parent) {

        LOG = 0;
        while (1<<LOG <= n) {
            ++LOG;
        }

        up = std::vector<std::vector<int>>(n, std::vector<int>(LOG));
        adj = std::vector<std::vector<int>>(n);

        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        depths = std::vector<int>(n);
        get_depths(adj);

        parent[0] = 0;
        for (int i = 0; i < n; ++i) {
            up[i][0] = parent[i];
        }
            for (int j = 1; j < LOG; ++j) {
                for (int i = 0; i < n; ++i) {
                    up[i][j] = up[ up[i][j-1] ][j-1];
                }
            }

    }
    int getKthAncestor(int node, int k) {

        if (depths[node] < k) return -1;
        for (int j = LOG -1; j >= 0; --j) {
            if (1<<j <= k) {
                node = up[node][j];
                k-= 1<<j;
            }
        }
        return node;
    }
};
