class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
            int n = nums.size();

    std::vector<int> sorted = nums;
    std::ranges::sort(sorted);

    std::vector<std::deque<int>> groups(1);
    std::unordered_map<int,int> pos;

    groups[0].push_back(sorted[0]);
    pos[sorted[0]] = 0;

    int group_count = 0;
    for (int i = 1; i < n; ++i) {
       if (abs(sorted[i-1] - sorted[i]) <= limit) {
       }
       else {
           ++group_count;
           groups.resize(groups.size() + 1);
       }
       groups[group_count].push_back(sorted[i]);
       pos[sorted[i]] = group_count;
    }

    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = groups[pos[nums[i]]].front();
        groups[pos[nums[i]]].pop_front();
    }
    return ans;


    }
};