#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using std::vector;
class Solution {
    
public:

    struct pair_hash {
        auto operator()(const std::pair<int,int> &p) const -> size_t {
                std::size_t h1 = std::hash<int>{}(p.first);
                std::size_t h2 = std::hash<int>{}(p.second);
                return h1 ^ (h2 << 1);
        }
    };
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) { 
        std::vector<int> k_sums;
        k_sums.push_back(std::accumulate(nums.begin(), nums.begin() + k, 0));
        for (int i = k; i < nums.size(); ++i) {
            int new_sum = k_sums.back() + nums[i] - nums[i - k];
            k_sums.push_back(new_sum);
        }


        std::unordered_map<std::pair<int,int>, int, pair_hash> dp;
        auto get_max_sum = [&nums, &k, &k_sums, &dp](auto &&f, int i, int count) -> int {
            if (count == 3 || i > nums.size() - k) return 0;

            if (dp.find({i, count}) != dp.end())
                return dp[{i, count}];


            int include = k_sums[i] + f(f, i + k, count + 1);
            int skip = f(f,i+1, count);

            dp[{i,count}] = std::max(include, skip);
            return dp[{i,count}];
        };

        auto get_indices = [&nums,&k, &get_max_sum, &k_sums]() {
            int i = 0;
            std::vector<int> indices;

            while (i <= nums.size() - k && indices.size() < 3) {
                int include = k_sums[i] + get_max_sum(get_max_sum,i + k, indices.size() + 1);
                int skip = k_sums[i] + get_max_sum(get_max_sum,i + 1, indices.size());
                if (include >= skip) {
                   indices.push_back(i) ;
                   i+=k;
                } else { ++i; }
            }
            return indices;
        };
        return get_indices();
    }
};

int main(int argc, char **argv){

    auto print_v = [](const auto &v) {
        for (const auto & i : v) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    };
    std::vector v = {1,2,3,4,5};

    std::make_heap(v.begin(), v.end());
    std::cout << v[0] << '\n';
    std::pop_heap(v.begin(), v.end());
    v.pop_back();
    std::cout << v[0] << '\n';
    std::pop_heap(v.begin(), v.end());
    v.pop_back();
    std::cout << v[0] << '\n';
    



    

    return 0;
}
