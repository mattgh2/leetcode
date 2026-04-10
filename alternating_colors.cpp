#include <iostream>
#include <vector>

auto fun(std::vector<int> &colors, int k) -> int {
    for (int i = 0; i < k - 1; ++i) {
        colors.push_back(colors[i]);
    }
    int n = colors.size();

    int l = 0, r = 1,ans = 0;
    while (r < n) {
        if (colors[r] == colors[r-1]) {
            l = r;
        }
        if ((r-l+1) == k) {
            ++ans;
            ++l;
        }
        ++r;

    }
    return (r-l+1 == k) ? ++ans : ans;
}


int main(int argc, char **argv){
    std::vector<int> v = {0,1,0,0,1,0,1};
    std::cout << fun(v,6);

    


    return 0;
}
