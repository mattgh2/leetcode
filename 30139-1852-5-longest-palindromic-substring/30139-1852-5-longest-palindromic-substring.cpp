class Solution {
public:
    string longestPalindrome(string s) {
        
    int n = s.size();
    int max = 0;
    std::string ans;
    if (s.size() == 1) return s;

    int best_left = 0; 
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n && i - j >= 0 && i + j < n; ++j) {
            if (s[i - j] != s[i +j]) { break; }
            int len = 2 * j + 1; 
            if (len > max) {
                max = len;
                best_left = i - j;
            }
        }
    }
    for (int i = 0; i < n  - 1; ++i) {
        for (int j = 1; j < n && i - j + 1 >= 0 && i + j < n; ++j) {
            if (s[i-j+1] != s[i+j]) { break; }
            int len = 2 * j;
            if (len > max) {
                max = len;
                best_left = i - j + 1;
            }
        }
    }
    return s.substr(best_left, max);

    }
};