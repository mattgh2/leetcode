

#include <vector>
#include <iostream>

auto fn(std::vector<int> &nums) -> long long {
    int n = nums.size();
    long long max = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n-1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (((nums[i] - nums[j]) * nums[k]) > max) {
                    max = (nums[i] - nums[j]) * nums[k];
                }
            }
        }
    }
    return max;
}
int main(int argc, char **argv){

    std::vector<int> v = {12,6,1,2,7};
    std::cout << fn(v) << '\n';


    return 0;
}
