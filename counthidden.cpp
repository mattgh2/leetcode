#include <iostream>
#include <vector>

auto solve(std::vector<int> &differences, int lower, int upper) -> int {
    int n = differences.size();


    int l = lower, r = upper;
    for (int i = 0; i < n; ++i) {
        if (l + differences[i] < lower) {
            l = lower;
        } else {
            l += differences[i];
        }
        if (r + differences[i] > upper) {
            r = upper;
        } else {
            r += differences[i];
        }

    }
    return (l > r) ? 0 : r - l + 1;

}
int main(int argc, char **argv){

    
    std::vector<int> v = {3,-4,5,1,-2};
    std::cout << solve(v, -4,5);


    return 0;
}
