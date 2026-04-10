#include <iostream>
#include <vector>
#include <unordered_map>


auto solve(std::vector<int> &answers) -> int { 
    int n = answers.size();

    std::unordered_map<int,int> mp;

    for (int i = 0; i < n; ++i) {
        ++mp[answers[i]];
    }

    int ans = 0;
    for (auto &[amount, freq] : mp) {
        while (freq > 0) {
            ans += amount + 1; 
            freq -= amount + 1;
        }
    }
    return ans;
}
int main(int argc, char **argv){

    std::vector<int> v = {1,1,2};
    std::vector<int> v2 = {10,10,10};
    std::cout << solve(v) << '\n';
    



    return 0;
}
