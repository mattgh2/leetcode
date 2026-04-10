
#include <iostream>
#include <vector>

auto solve(std::vector<int> &arr, int a, int b, int c) -> int {
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (std::abs(arr[i] - arr[j]) <= a && std::abs(arr[j] - arr[k]) <= b && std::abs(arr[i] - arr[k]) <= c) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

int main(int argc, char **argv){

    
    std::vector<int> v = {3,0,1,1,9,7};
    std::cout << solve(v,7,2,3) << '\n';


    return 0;
}
