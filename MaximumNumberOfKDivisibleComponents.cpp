
#include <vector>
#include <iostream>

using std::vector;
class Solution {
public:
    typedef std::vector<int> vi;
    typedef std::vector<std::vector<int>> vii;

    auto dfs(int s,int came_from, vii &adj, std::vector<int> &sum, vi &values) -> int {

        sum[s] = values[s]; 
        for (const auto &u : adj[s]) {
            if (u != came_from) {
                sum[s] += dfs(u, s, adj, sum, values);
            }
        }
        return sum[s];
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Convert to a adj list.
        vii adj(n);
        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        
        vi sum(n,0);

        dfs(0,-1, adj, sum,values);

        int count{};
        for (const auto &i : sum) {
            std::cout << i << ", ";
        }
        std::cout << '\n';


        return count;
    }     

};

int main(int argc, char **argv){
        

    int n = 5, k = 6;
    std::vector<std::vector<int>> edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    std::vector<int> values = {1,8,1,4,4};
    Solution sol;

    sol.maxKDivisibleComponents(n,edges,values,k);

    return 0;

}
