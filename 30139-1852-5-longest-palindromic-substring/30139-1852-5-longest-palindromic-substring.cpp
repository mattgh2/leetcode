class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        int max = 1;
        std::string ans;
        int best_left = 0;
        for (int i = 0; i < n - 1; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > max) {
                    max = len;
                    best_left = l;
                }
                --l, ++r;
            }
            l = i, r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > max) {
                    max = r - l + 1;
                    best_left = l;
                }
                --l, ++r;
            }
        }
        return s.substr(best_left, max);
    }
};