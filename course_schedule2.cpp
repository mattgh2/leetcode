#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
    enum visit_states {unvisited, visiting, visited};

    auto dfs(int s, std::vector<visit_states> &states, std::vector<std::vector<int>> &adj, std::vector<int> &order) -> bool {
        states[s] = visiting;

        for (const auto &u : adj[s]) {
            if (states[u] == visiting) {
                return false;
            }
            if (states[u] == unvisited) {
                if (dfs(u, states, adj, order))
                    return false;
            }
        }
        states[s] = visited;
        order.push_back(s);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            adj[a].push_back(b);
        }

        std::vector<visit_states> states(numCourses, unvisited);
        std::vector<int> ordering;
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(i, states,adj,ordering))
                return {};
        }

        std::reverse(ordering.begin(),ordering.end());
        return ordering;
    }
};






int main(int argc, char **argv){

    std::vector<std::vector<int>> v = {{0,1},{1,2},{2,3}}   ;
    Solution solution;
    std::vector<int> v2 = solution.findOrder(4,v);


    return 0;
}
