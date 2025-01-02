#include <vector>
#include <unordered_set>
class Solution {
public:
typedef std::vector<std::vector<int>> vii;
    bool canFinish(int numCourses, vii &prerequisites)  {
        std::vector<std::vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int a = prerequisites[i][1], b = prerequisites[i][0];
            adj[a].push_back(b);
        }

        std::unordered_set<int> visited;
        auto dfs = [&](auto &&ff, int vertex) -> bool {
            if (visited.find(vertex) != visited.end()) return true;
            visited.insert(vertex);
            for (const auto &u :adj[vertex]) {
                return ff(ff,u);
            }
            return false;
        };

        for (int i = 0; i < numCourses; ++i) {
            visited.clear();
            if (dfs(dfs, i)) return false;
        }

        return true;
    }

};
int main(int argc, char **argv){

    


    return 0;
}
