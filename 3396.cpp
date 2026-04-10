#include <vector>
#include <iostream>
#include <bitset>

auto solve(std::vector<int> &nums) {
  int ans = 0, n = nums.size();
        int count[101] = {0};
        std::bitset<101> bs;
        for (int i = 0; i < n; ++i) {
            ++count[nums[i]];
            if (count[nums[i]] > 1) {
                bs[nums[i]]  = 1;
            }
        }
        int i;
        for (i = 0; i < n - 2; i+=3) {
            if (bs.count() == 0) {
                return ans;
            }
            for (int j = i; j < i + 3 && j < n; ++j) {
                if (--count[nums[j]] < 2) {
                    bs[nums[j]] = 0;
                }
            }
            ++ans;
        }
        return bs.count() == 0 ? ans : ans +1;
}

int main(int argc, char **argv){
    std::vector<int> v = {1,2,3,4,2,3,3,5,7};
    std::vector<int> v2 = {4,5,6,4,4};

    std::cout << solve(v) << '\n';
    std::cout << solve(v2);
    return 0;
}
