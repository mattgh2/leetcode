#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) { 
        int ans=0;
        std::unordered_map<int,int> mp;
        std::vector<int> prefix(nums.size());

        mp[0] = 1;
         
        prefix[0] = nums[0];
        mp[prefix[0]] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = nums[i] + prefix[i - 1];
            int x = prefix[i] - k;
            if (mp.find(x) != mp.end()) ++ans;
            ++mp[prefix[i]];
        }

        return ans;
    }

};

