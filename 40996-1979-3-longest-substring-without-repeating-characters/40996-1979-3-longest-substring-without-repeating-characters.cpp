class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 1)
            return 1;

        int max = 0;
        std::unordered_set<char> sp;
        sp.insert(s[0]);

        int l = 0, r = 1;
        while (r < n) {
            if (sp.find(s[r]) != sp.end()) {
                while (s[l] != s[r]) {
                    sp.erase(s[l]);
                    ++l;
                }
                ++l;
            }
            sp.insert(s[r]);
            max = std::max(max, r - l + 1);
            ++r;
        }
        return max;
    }
};