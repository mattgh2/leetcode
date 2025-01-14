class Solution {
public:
    string longestPalindrome(string s) {
        std::string t;
        for (const auto& ch : s) {
            t += std::string("#") + ch;
        }
        t += '#';
        int n = t.size();
        std::vector<int> p(n);

        int l = 0, r = 0, center = 0, max_len = 0;
        for (int i = 1; i < n; ++i) {
            if (i < r) {
                p[i] = std::min(r-i, p[l + (r-i)]);
            }

            while (i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) {
                ++p[i];
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
            if (p[i] > max_len) {
                max_len = p[i];
                center = i;
            }
        }
        int start = (center / 2) - (max_len - 1) / 2;
        return s.substr(start, max_len - 1);
    }
};