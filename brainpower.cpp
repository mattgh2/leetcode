#include <iostream>
#include <vector>
#include <unordered_map>

typedef std::vector<std::vector<int>> vii;
auto fn(vii &questions) -> long long {
    int n = questions.size();
    std::vector<int> dp(n);
    dp[n-1] = questions[n-1][0];
    for (int i = n - 2; i >= 0; --i) {
        int next = questions[i][1] + i + 1;
        int take = questions[i][0] + ((next < n) ? dp[next] : 0);
        dp[i] = std::max(take, dp[i+1]);
    }
    return dp[0];
}
int main(int argc, char **argv){

    vii v = {
        {21,5},
        {92,3},
        {74,2},
        {39,4},
        {58,2},
        {5,5},
        {49,4},
        {65,3}
    };
    std::cout << fn(v) << '\n';
    


    return 0;
}
