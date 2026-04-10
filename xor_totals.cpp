#include <iostream>
#include <vector>

auto fn(std::vector<int> &nums) -> int {
    int n = nums.size();
    int ans = 0;

    for (int i = 1; i < (1<<n); ++i) {
        int subset = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) {
                subset ^= nums[j];
            }
        }
        ans += subset;
    }
    return ans;
}
int main(int argc, char **argv){

    std::vector<int> v = {1,3};
 
    std::cout <<fn(v) << '\n';

    return 0;
}
