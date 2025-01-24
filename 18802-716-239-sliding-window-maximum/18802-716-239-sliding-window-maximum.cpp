class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> lg(n + 1);

        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i/2] + 1;
        }

        std::vector<std::vector<int>> st(lg[n] + 1, std::vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            st[0][i] = nums[i];
        }

        for (int p = 1; p <= lg[n]; ++p) {
            for (int i = 0; i + (1 << p) <= n; ++i) {
                st[p][i] = std::max(st[p-1][i], st[p-1][i + (1<<(p-1))]);
            }
        }

        std::vector<int> ans(n - k + 1,0);
        for (int i = k - 1; i < n; ++i) {
            int l = i - k + 1, r = i;
            ans[i - k + 1] = std::max(st[lg[r-l+1]][l], st[lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
        }
        return ans;
    }
};