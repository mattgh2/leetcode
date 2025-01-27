class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
            std::vector<std::vector<int>> adj(numCourses);
    std::vector<std::bitset<101>> pre(numCourses); 
    std::vector<int> in(numCourses);

    
    for (const auto &v : prerequisites) {
        adj[v[0]].push_back(v[1]);
        pre[v[1]][v[0]] = 1;
        ++in[v[1]];
    }

    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (const auto &u : adj[c]) {
            pre[u] |= pre[c];
            if (--in[u] == 0) {
                q.push(u);
            }
        }
    }
    std::vector<bool> ans(queries.size());
    for (int i = 0; i < (int)queries.size(); ++i) {
        int s = queries[i][0], t = queries[i][1];
        ans[i] = pre[t][s];
    }
    return ans;

    }
};