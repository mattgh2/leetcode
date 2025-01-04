class Solution {
public:
    int findMin(vector<int>& nums) {
            int n = nums.size();
    int l = 0, r = n -1;

    int ans = INT_MAX;
    while (l <= r) {
        int mid = l + (r-l) / 2;
        int value = nums[mid], last = nums[r];

        if (value > last)  {
            l = mid + 1;
        }
        else {
            ans = std::min(ans, value);
            r = mid - 1;
        }
    }
    return ans; 

    }
};