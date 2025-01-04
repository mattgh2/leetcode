class Solution {
public:
    int search(vector<int>& nums, int target) {
            int n = nums.size();
    int l = 0, r = n - 1;

    int first = nums[0];
    while (l <= r) {
        int mid = l + (r - l) /2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] >= first == target >= first) {
            if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        else {
            if (nums[mid] >= first) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }
    return -1;

    }
};
