#include <vector>
#include <iostream>

using std::vector;
class Solution {
public:
    typedef std::vector<int> vi;
    auto acc(const vi &indices, const vi &nums, int k) -> int {  
        int sum = 0;
        for (int i = 0 ; i < indices.size(); ++i) {
            for (int j = indices[i]; j < indices[i] + k; ++j) {
                sum += nums[j];
            }
        }
        return sum;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int max = 0;
        auto go = [&](auto &&f, int i, int k, vi &nums, vi take)-> vi {
            if (i > (int)nums.size()) {
                return {};
            }

            if (take.size() == 3) { 
                int sum = acc(take, nums, k);
                if (sum > max) {
                    max = sum;
                    return take; 
                }
                return {};
            }

            take.push_back(i);
            auto bl = f(f,i + k, k, nums, take);
            take.pop_back();
            auto br = f(f,i + 1, k, nums, take);

            if (acc(bl,nums,k) > acc(br,nums,k)) return bl;
            else return br;

        };
        return go(go, 0,k,nums,{});
    }
    
};

int main(int argc, char **argv){

    std::vector v = {1,2,1,2,6,7,5,1};

    int k = 2;

    Solution sol;
    
    std::vector<int> ans = sol.maxSumOfThreeSubarrays(v,k);

    for (const auto & i : ans) {
        std::cout << i << '\n';
    }

    return 0;
}
