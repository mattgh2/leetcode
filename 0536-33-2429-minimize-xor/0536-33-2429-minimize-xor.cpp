class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int bitcount_num1 = __builtin_popcount(num1);
        int bitcount_num2 = __builtin_popcount(num2);
        int diff = std::abs(bitcount_num1 - bitcount_num2);
        int x = num1;
        while (diff > 0) {
            if (bitcount_num1 > bitcount_num2) {
                x &= x-1;
            }
            else {
                x |= x + 1;
            }
            --diff;
        }
        return x;
    }
};