#include <vector>
#include <limits>
#include <unordered_map>
#include <iostream>
#include <string>

/**
 * Bottom-UP solution. 
 */
using std::vector;
class Solution1 {
public:
    typedef std::pair<int,int> ii;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        std::vector<int> dp(days.size() + 1, std::numeric_limits<int>::max());
        std::vector<ii> cc = {{costs[0], 1}, {costs[1], 7}, {costs[2], 30}};
        dp[days.size()] = 0;

        for (int i = days.size() - 1; i >= 0; --i) {
            int j = i;
            for (const auto & [c,d] : cc) {
                while (j < days.size() && days[j] < days[i] + d) {
                    ++j;
                }
                dp[i] = std::min(dp[i], dp[j] + c);
            }
        }

        return dp[0];
    }

};

/**
 * Recursive solution w/ memoization.
 */
class Solution2 {
    std::unordered_map<int,int> dp;
public:
    auto dfs(int index, std::vector<int> &days, std::vector<std::pair<int,int>> &cost) -> int {
        if (index == days.size()) return 0;

        if (dp.find(index) != dp.end()) return dp[index];
        
        dp[index] = std::numeric_limits<int>::max();
        int j = index;
        for (const auto & [c,duration] : cost) {
            while (j < days.size() && days[j] < (days[index] + duration)) 
                ++j;
            dp[index] = std::min(dp[index], c + dfs(j,days,cost));
        }
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         std::vector<std::pair<int,int>> c = {{costs[0],1},{costs[1],7},{costs[2], 30}};
            
        return dfs(0,days, c);
    }
};

/**
 * Recursive solution for target sum using memo.
 */
class Solution3 {
public:
    typedef std::unordered_map<std::string,int> cache;
    cache dp;
public:

    auto go(int current_sum, vector<int> &nums, int target, int i = 0) -> int {
        if (i >= nums.size()) {
            return current_sum == target ? 1 : 0;
        }
        std::string key = std::to_string(current_sum) + "," + std::to_string(i);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int count = 0;
        count += go(current_sum + nums[i], nums, target, i + 1);


        count += go(current_sum - nums[i], nums, target, i + 1);
        
        dp[key] = count;
        return dp[key];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return go(0, nums, target);
    }
};

/**
 * dp solution. Bottom up ** 2D **
 */
class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        
        // Sum -> count
        std::vector<std::unordered_map<int,int>> dp(nums.size() + 1);
        dp[0][0] = 1;
        for (int i = 0; i < nums.size();++i) {
            for (const auto & [a,b] : dp[i]) {
                dp[i + 1][a-nums[i]] += b;
                dp[i+1][a+nums[i]] +=b;
            }
        }
        return dp[nums.size()][target];
    }
    
};

int main(int argc, char **argv){

    std::vector<int> nums = {1,1,1,1,1};
    int target = 3;

    Solution sol;
    std::cout << sol.findTargetSumWays(nums,target);

    const int x = 01;
        for(int i = 0 ; i < 10 ; ++i ) {
            
        }

    return 0;
}
