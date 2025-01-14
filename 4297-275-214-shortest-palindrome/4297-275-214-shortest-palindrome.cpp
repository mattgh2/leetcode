class Solution {
public:
    auto kmp(std::string s) -> std::vector<int> {
        s += std::string("#") + std::string(s.rbegin(), s.rend());
        int n = s.size();

        std::vector<int> pi(n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            pi[i] = j;
        }
        return pi;
    }

    string shortestPalindrome(string s) {
        auto pi = kmp(s);
        std::string t = s.substr(pi[pi.size() - 1]);
        return std::string(t.rbegin(), t.rend()) + s;
    }
};