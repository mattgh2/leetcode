#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    typedef std::pair<int,int> ii;
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)  {
            
        std::unordered_map<int,int> mp;
        for (const auto &num : nums) { ++mp[num]; }

        std::vector<ii> fq;
        for (const auto &pair : mp) {
            fq.emplace_back(pair.second, pair.first);
        }
        auto pair_comp = [](const auto &a, const auto &b) {
            return a.first < b.first;
        };

        std::make_heap(fq.begin(), fq.end(), pair_comp);


        std::vector<int> result(k);

        int i = 0;
        while (k > 0) {
            result[i] = fq[0].second;
            std::pop_heap(fq.begin(), fq.end() - i);
            ++i, --k;
        }
        return result;
    }

};
int main(int argc, char **argv){

    
    std::vector<int> v = {5,3,1,1,1,3,5,73,1};

    Solution solution;

    auto res = solution.topKFrequent(v,3);

     for (const auto & i : res) {
         std::cout << i << '\n';
     }
     std::cout << '\n';

    return 0;
}
