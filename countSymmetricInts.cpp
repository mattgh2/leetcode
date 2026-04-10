#include <iostream>
#include <vector>
#include <cstring>

const int N = 1e4;
int LOG[N+1];

auto solve(int low, int high) -> int {
    memset(LOG,0,sizeof(LOG));
    for (int i = 10; i <= N; ++i) {
        LOG[i] = LOG[i/10] + 1;
    }
    int ans = 0;
    for (int i = low; i <= high; ++i) {
        int num = i, n = LOG[i];
        if (!((n+1)&1)) {
            int mid = n/2;
            int sum1 = 0, sum2 = 0;
            for (int k = 0; k < n+1; ++k) {
                (k > mid) ? sum1 += num%10 : sum2 += num%10;
                num/=10;
            }
            if (sum1 == sum2) ++ans;
        }
    }
    return ans;

}
int main(int argc, char **argv){

    std::cout << solve(1,100) << '\n';
    


    return 0;
}
