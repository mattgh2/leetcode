#include <iostream>
#include <vector>
#include <unordered_map>



class Solution {
public:

    typedef std::vector<std::vector<int>> vii;
    enum states {unvisited, visiting, visited};
    auto dfs(int &count, int s, std::vector<states> &visit, std::unordered_map<int,std::vector<int>> &adj, int came_from) -> bool {
        visit[s] = visiting;

        for (const auto &u : adj[s]) {
            if (visit[u] == visiting && u != came_from) 
                return true;
            if (visit[u] == unvisited)
                if (dfs(count,u,visit,adj, s)) {
                    return true;
                }
        }
        count++;
        visit[s] = visited;
        return false;
    }
    bool validTree(int n, std::vector<std::vector<int>> &edges)  {
        // We have the size so we could have used a vector instead of a hm.
        std::unordered_map<int, std::vector<int>> adj;
        for (const auto &v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        std::vector<states> visited(adj.size(), unvisited);
        int count = 0;
           if (dfs(count,adj.begin()->first, visited, adj, adj.begin()->first) || count < n) return false;

        return true;
    }
};

int main(int argc, char **argv){
    
    Solution::vii edges = {{0,1},{0,2},{0,3},{1,4}};
    Solution::vii edges2 = {{0,1},{1,2},{2,3},{1,3},{1,4}};

    Solution solution;

    std::cout << std::boolalpha << solution.validTree(5,edges) << '\n';
    std::cout << std::boolalpha << solution.validTree(5,edges2) << '\n';

    
    return 0;
}
