#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>

std::bitset<1000> seen;


auto solve(std::vector<int> &digits) -> std::vector<int> {

    int n = digits.size();

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (digits[i] == 0) continue;
        int num = digits[i];
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int b = num * 10 + digits[j];
            for (int k = 0; k < n; ++k) {
                if (k == j || k == i) continue;
                int c = b * 10 + digits[k];
                if ((c&1) == 0 && seen[c] == 0) {
                    ans.push_back(c);
                }

            }
        }
    }
    std::ranges::sort(ans);
    return ans;
}
auto better_soln(std::vector<int> &digits) -> std::vector<int> {
    int n = digits.size();
    int freq[10];
    memset(freq,0, sizeof(freq));
    for (int i = 0; i < n; ++i) {
        ++freq[digits[i]];
    }
    std::vector<int> ans;
    for (int i = 100; i < 1000; i += 2) {
        int a[10] = {0};
        for (int num = i; num > 0; num /= 10) {
            ++a[num%10];
        }
        bool ok = true;
        for (int i = 0; i < 10 && ok; ++i) {
            if (a[i] > freq[i]) ok = false;
        }
        if (ok) ans.push_back(i);
    }
    return ans;

}
int main(int argc, char **argv){

    
    std::vector<int> digits = {2,1,3,0};
    auto ans = solve(digits);

    for (const auto & i : ans) {
        std::cout << i << '\n';
    }
    std::cout << '\n';


    return 0;
}
