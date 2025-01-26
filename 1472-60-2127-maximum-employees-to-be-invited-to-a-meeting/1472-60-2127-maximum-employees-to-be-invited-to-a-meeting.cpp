class Solution {
public:

    auto cycle_find(int s, std::vector<std::vector<int>> &adj, std::vector<int> &visited, int &count) -> bool {

        visited[s] = 1;

        for (const auto & u : adj[s]) {
            if (visited[u] == 1) {
                ++count;
                return true;
            }
            else if (visited[u] == 0) {
                if (cycle_find(u, adj ,visited,count)) {
                    ++count;
                    return true;
                }
            }
        }
        visited[s] = 2;
        return false;

    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        std::vector<int> in(n,0);
        std::vector<int> chain_lengths(n,0);
        std::vector<int> visited(n,0);

        for (int i = 0; i < n; ++i) {
            ++in[favorite[i]];
        }

        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int c = q.front();
            q.pop();

            visited[c] = 1;

            int next = favorite[c];
            chain_lengths[next] = chain_lengths[c] + 1;

            if (--in[next] == 0) {
                q.push(next);
            }
        }
        int max_cycle = 0, total_chains = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0)  {
                int c = i, cycle_length = 0;

                while (visited[c] == 0) {
                    visited[c] = 1;
                    c = favorite[c];
                    ++cycle_length;
                }

                if (cycle_length == 2) {
                    total_chains += 2 + chain_lengths[i] + chain_lengths[favorite[i]];
                }
                else {
                    max_cycle = std::max(max_cycle, cycle_length);
                }
            }

        }
        return std::max(max_cycle, total_chains);

    }
};