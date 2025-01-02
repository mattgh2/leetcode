#include <vector>
#include <numeric>

using std::vector;
class Solution {
public:
    auto dfs(int s, std::vector<std::vector<int>> &adj, std::vector<bool> &visited) -> void { 
        visited[s] = true;

        for (const auto & u : adj[s]) {
            if (visited[u] == false) {
                dfs(u,adj,visited);
            }
        }
    }

   int countComponents(int n, vector<vector<int>>& edges) {
       int ans{};

       std::vector<std::vector<int>> adj(n);
       for (const auto &edge :edges) {
           adj[edge[0]].push_back(edge[1]);
           adj[edge[1]].push_back(edge[0]);
       }

       std::vector<bool> visited(n,false);
       size_t count{};
       for (int i = 0; i < n; ++i) {
           if (visited[i] == false) {
               dfs(i,adj, visited);
               ++ans;
           }
       }


       return ans;
    } 

};
int main(int argc, char **argv){

    


    return 0;
}
