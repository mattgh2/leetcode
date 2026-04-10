
#include <iostream>
#include <cmath>

const int MAX_EVEN = 5;
const int MAX_PRIME = 4;
const int MOD = 1e9 + 7;

typedef unsigned long long ull;
auto go(int l, int r) -> ull {
    if ((r - l + 1) <= 10) {
        int evens = (r-l+1)>>1;
        int primes = (r-l+1)>>1;
        if ((r - l +1)&1) {
            l&1 ? ++primes : ++evens;
        }
        return ((ull)pow(5,evens)) * ((ull)pow(4,primes));
    }

    ull mid = l + ((r - l) >> 1);
    ull ans = (go(l,mid)% MOD) * (go(mid+1,r) % MOD);
    return ans % MOD;
}



auto fast_exp(ull a, ull n) -> ull {
    ull ans = 1;
    while (n > 0) {
        int last_bit = n & 1;

        if (last_bit) {
            ans = (ans * a) % MOD;
        }
        a *= a;
        n >>= 1;
    }
    return ans % MOD;

}
auto solve(long long n) -> int {
    ull evens = (int)((double)(n)/2+0.5);
    ull odds = n >> 1;
    return (fast_exp(MAX_EVEN,evens) * fast_exp(MAX_PRIME,odds)) % MOD;
}



int main(int argc, char **argv){

    
    std::cout << solve(50) << '\n';



    return 0;
}
