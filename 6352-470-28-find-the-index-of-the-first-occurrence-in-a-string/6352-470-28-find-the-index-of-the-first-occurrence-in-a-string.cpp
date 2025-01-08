class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(), m = haystack.size();
        std::vector<int> pi(n);

        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j-1];
            }
            if (needle[i] == needle[j]) {
                ++j;
            } 
            pi[i] = j;
        }
        int i = 0, j = 0;
        while (i < m) {
            if (haystack[i] == needle[j]) {
                ++i, ++j;
            }
            else {
                if (j == 0) ++i;
                else {
                    j = pi[j - 1];
                }
            }
            if (j == n) return i - n;
        }
        return -1;


    }
};