#include <iostream>
#include <vector>
#include <bitset>

auto solve(std::vector<int> &nums) -> int {
    int n = nums.size();
    std::bitset<(int)1e3*2+1> bs;
    for (int i = 0; i < n; ++i) {
        bs[nums[i]] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        std::bitset<(int)1e3*2+1> current;
        current[nums[i]] = 1;
        for (int j = i; j < n; ++j) {
            current[nums[j]] = 1;

            if (current.count() == bs.count()) {
                ++ans;
            }
        }
    }
    return ans;

}
int main(int argc, char **argv){

    
    std::vector<int> v = {1,3,1,2,2};

    std::cout << solve(v) << '\n';

    return 0;
}
