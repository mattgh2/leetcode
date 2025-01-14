class Solution {
public:
    auto manachers(std::string s) -> int {
        std::string t;
        for (const auto & ch : s) {
            t+= std::string("#") + ch;
        }
        t+= '#';

        int n = t.size();
        std::vector<int> p(n);

        int l = 0, r = 0, count = 0;
        for (int i = 1; i < n; ++i) {
            if (i < r) {
                p[i] = std::min(r-i,p[l+(r-i)]);
            }
            while (i + p[i] < n && i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]]) {
                ++p[i];
            }
            --p[i];
            if (i + p[i] < r) {
                l = i - p[i];
                r = i + p[i];
            }
            count+= p[i] / 2;
        }
        return count;
    }
    int countSubstrings(string s) {
        return s.size() + manachers(s);
    }
};