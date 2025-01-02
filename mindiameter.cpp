#include <iostream>
#include <unordered_map>
#include <vector>


class Solution {
    typedef std::vector<int> vi;
    typedef std::vector<std::vector<int>> vii;
    typedef std::pair<int,int> ii;
public:
    auto get_diameter(auto &adj_list, int s, int came_from) -> ii {

        ii max_diameter = {0,s};

        for (const auto & u : adj_list[s]) {
            if (u != came_from)  {
                auto result = get_diameter(adj_list, u, s);
                result.first += 1;
                if (result.first > max_diameter.first) {
                    max_diameter = result;
                }
            }
        }
        return max_diameter;

        

    }

    int minimumDiameterAfterMerge(vii &edges1, vii &edges2) {
        auto make_adj = [](const auto &edge_list, auto &adj_list) {
            for (const auto & edge : edge_list) {
                adj_list[edge[0]].push_back(edge[1]);
                adj_list[edge[1]].push_back(edge[0]);
            }
        };
        std::unordered_map<int,vi> adj1, adj2;

        make_adj(edges1,adj1); make_adj(edges2,adj2);

        int first = get_diameter(adj1, 0,-1).second;
        auto d1 = get_diameter(adj1, first,-1);

        int first2 = get_diameter(adj2, 0,-1).second;
        auto d2 = get_diameter(adj2, first2,-1);
         

        return std::max(std::max(d1.first,d2.first), d1.first/2 + d2.first/2 + 1);

    }
};



int main(int argc, char **argv){
    
    

    // vii edges1 = {{0,1},{0,2},{0,3}};
    // max diameter of adj1, or max diameter of adj2 or max diameter of the two combined.
    std::vector<std::vector<int>> edges1 = {
        {0, 1},
        {0, 2},
        {0, 3},
        {2, 4},
        {2, 5},
        {3, 6},
        {2, 7}
    };
std::vector<std::vector<int>> edges2 = {
        {0, 1},
        {0, 2},
        {0, 3},
        {2, 4},
        {2, 5},
        {3, 6},
        {2, 7}
    };

    
    Solution sol;
    std::cout << sol.minimumDiameterAfterMerge(edges1, edges2);
    



    return 0;
}
