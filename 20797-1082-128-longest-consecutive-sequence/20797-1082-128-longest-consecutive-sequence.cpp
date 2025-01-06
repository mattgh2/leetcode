class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        std::unordered_map<int,int> mp;

        for (const auto & num : nums) {
            if (mp[num] == 0) {
                mp[num] = mp[num-1] + mp[num+1] + 1;
                mp[num - mp[num-1]] = mp[num];
                mp[num + mp[num+1]] = mp[num];
                ans = max(ans,mp[num]);

            }
        }

        return ans; 
    }
};