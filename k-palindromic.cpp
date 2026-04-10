
#include <vector>
#include <iostream>
#include <cmath>
#include <bitset>

// Check if the count of every digit is div by 2, except for at most 1.
// If we meet this condition, If there is no even pair of positive integers, then it cannot be done.
// Except for when k = 1, then its fine.
//
// Construct the palindrome with two pointers? 
// -- ensure that we do not start with zero.
// -- Odds must go in the middle
//
// We can use a bitset with bit flipping to check if there is a even amount for each digit 0-9, 
// (bs.count() == 1) will suffice.
// But how do we get the count? (for construction)
// Freq array? (might be costly if we do this n * 10 times)
// For construction, initialize a string to be the amount of digits.

std::bitset<10> bs;
int freq[10];

const int MAX_D = 12;
const int D = 9;

auto good(int n, int x, int k) -> int {
    for (int i = x; i > 0; i/=10) {

        int digit = i % 10;
        bs.flip(digit);

        if (freq[digit] == MAX_D) {
            freq[digit] = 0;
        }
        ++freq[digit];
    }

    if (bs.count() > 1) return -1;

    bool ok = false;
    for (int i = 1; i <= D && !ok; ++i) {
        if (freq[i] > 0 && !(freq[i]&1)) {
            ok = true;
        }
    }

    if (!ok && k > 1) return false;

    std::string pal(n,'F');

    int odd = -1;
    int l = 0, r = n-1;
    for (int i = D; i >= 0; --i) {
        if (freq[i]&1) {
            odd = i;
            continue;
        }
        while (freq[i] > 0) {
            pal[l++] = i+48;
            pal[r--] = i+48;
            freq[i] -= 2;
        }
        freq[i] = MAX_D;
    }
    if (odd != -1) {
        while (freq[odd])  {
            pal[l++] = odd+48;
            --freq[odd];
        }
    }
    return 1;
}
auto solve(int n, int k) -> long long {
    long long ans = 0;

    int start = pow(10,n-1);
    for (int i = start; i < start * 10; ++i) {

    }

    good(9,112233440,2);
    return 1;
}

int main(int argc, char **argv){

    
    solve(1,1);


    return 0;
}
