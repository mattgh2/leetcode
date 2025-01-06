class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int>ans(n);

        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int acc_right = 1;
        for (int i = n -1; i >= 0; --i) {
            ans[i] *= acc_right;
            acc_right *= nums[i];
        }
        return ans;
    }
};