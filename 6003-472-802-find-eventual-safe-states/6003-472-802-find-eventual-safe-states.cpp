class Solution {
public:
    typedef std::vector<std::vector<int>> vii;
    bool dfs(int s, vii &adj, std::vector <int> &safe, std::vector<int> &visited) {

        visited[s] = 1;

        for (const auto & u : adj[s]) {
            if (visited[u] == 1) {
                return false;
            }
            else if (visited[u] == 0) {
                if (!dfs(u,adj,safe,visited)) {
                    return false;
                }
            }
        }
        visited[s] = 2;
        safe[s] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        std::vector<int> safe(n,0);
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty()) {
                safe[i] = 1;
            }
        }
        std::vector<int> visited(n,0);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                dfs(i, graph, safe,visited);
            }
        }
        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) ans.push_back(i);
        }
        return ans;
    }
};