#include <iostream>
#include <vector>
#include <algorithm>
auto lower_b(std::vector<int> &nums, int t, int l, int r) -> int {
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        if (nums[mid] >= t) {
            r = mid;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        }
        else {
            l = mid + 1;
        }
    }
    if (nums[l] < t) return -1;
    return l;
}

auto upper_b(std::vector<int> &nums, int t, int l, int r) -> int {
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        if (nums[mid] > t) {
            r = mid;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        }
        else {
            l = mid + 1;
        }
    }
    if (l - 1 < 0 || nums[l-1] > t) {
        return -1;
    }
    return l -1;
}

auto solve(std::vector<int> & nums, int lower, int upper) -> long long {
    int n = nums.size();
    std::ranges::sort(nums);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int min = (nums[i] < 0) ? lower + -nums[i] : lower - nums[i];
        int max = (nums[i] < 0) ? upper + -nums[i] : upper - nums[i];

        int lb = lower_b(nums,std::min(min,max), 0,n-1);
        int ub = upper_b(nums,std::max(min,max), 0,n);

        if (lb == -1 || ub == -1 || ub < lb) {
            continue ;
        }
        ans += (ub - lb) + 1;
        if (i >= lb && i <= ub) {
            --ans;
        }
    }

    return ans == 1 ? ans : ans / 2;


}
int main(int argc, char **argv){

    
    std::vector<int> v = {0,0,0,0,0,0};

    std::cout << solve(v,0,0) << '\n';

    return 0;
}
