
#include <iostream>
#include <vector>
auto solve(std::vector<int> &nums) -> bool {
    int n  = nums.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (count == 3) return true;
        if (nums[i]&1) ++count;
        else {
            count = 0;
        }
    }
    return false;
}
int main(int argc, char **argv){



    return 0;
}
