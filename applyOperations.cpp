#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <queue>

const int MOD = 1e9+7;
auto get_prime_factors(int x, std::vector<bool> &prime) -> int {
    int count = 0;
    std::unordered_set<int> vis;
    while (x > 1) {
        bool found = false;
        if (prime[x]) {
            return vis.find(x) == vis.end() ? count + 1 : count;
        }
        for (int i = 2; i <= std::sqrt(x) && !found; ++i) {

            if (prime[i] && x % i == 0) {
                x/=i;
                found = true;
                if (vis.find(i) == vis.end()) {
                    ++count;
                    vis.insert(i);
                }
            }

        }
    }
    return count;

}
 int qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
        }
        return (int) ans;
    }
auto fn(std::vector<int> &nums, int k) -> int {
    int n = nums.size();
    int high = *std::ranges::max_element(nums);

    std::vector<bool> prime(high + 1, 1);
    std::vector<int> prime_score(n);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::less<>> pq;

    for (int i = 2;(i * i) <= high; ++i) {
        for (int j = i * i; j <= high; j+=i) {
            prime[j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        pq.push({nums[i],i});
        prime_score[i] = get_prime_factors(nums[i], prime);
    }

    std::vector<int> right(n,-1);
    std::stack<int> mono;
    for (int i = n - 1; i >= 0; --i) {
        while (!mono.empty() && prime_score[i] >= prime_score[mono.top()]) {
            mono.pop();
        }
        if (!mono.empty()) {
            right[i] = mono.top();
        }
        mono.push(i);
    }

    std::vector<int> left(n,-1);
    while (!mono.empty()){
        mono.pop();
    }
    for (int i = 0; i < n; ++i) {
        while (!mono.empty() && prime_score[i] > prime_score[mono.top()]) {
            mono.pop();
        }
        if (!mono.empty()) {
            left[i] = mono.top();
        }
        mono.push(i);
    }
    int score = 1;
    while (k > 0) {
        auto [largest, idx]= pq.top();
        pq.pop();
        long long r = right[idx] != -1 ? right[idx] - 1 : n - 1;
        long long l = left[idx] != -1 ? left[idx] + 1 : 0;

        long long total = 1 + r - idx + idx - l + ((idx - l) * (r - idx));
        score = ((long long)(score % MOD) * qpow(largest, (int)total < k ? total : k) % MOD);

        k-= (total < k) ? total : k;
    }

    return score % MOD;
}


int main(int argc, char **argv){

    std::vector<int> v(1e4);
    v[0] = 30;
    std::fill(v.begin() + 1, v.end(), 2);
    int k = 1e4;
    std::cout << fn(v,k);
    


    return 0;
}
