class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            int n = nums.size();
    int l = 0, r =  n - 1;
    std::vector<int> ans(2,-1);

    while (l <= r) {
        int mid = l + (r-l) / 2;
        int value = nums[mid];
        if (value == target) {
            ans[0] = mid;
            r = mid  - 1;
        }
        else {
            if (target < value) {
               r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }
    l = 0, r = n  - 1;
    while (l <= r) {
        int mid = l + (r-l) / 2;
        int value = nums[mid];
        if (value == target) {
            ans[1] = mid;
            l = mid + 1;
        }
        else {
            if (target < value) {
               r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }
    

    return ans;

    }
};