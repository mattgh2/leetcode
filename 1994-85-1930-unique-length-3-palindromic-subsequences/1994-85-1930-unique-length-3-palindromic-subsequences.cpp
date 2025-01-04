class Solution {
public:
    int countPalindromicSubsequence(string s) {
            std::unordered_map<char, int> right;
    std::unordered_set<char> left;
    std::unordered_set<std::string> seen;

    left.insert(s[0]);
    for (int i = 1; i < s.length(); ++i) {
        ++right[s[i]];
    }
    for (int m = 1; m < s.length() - 1; ++m) {
        --right[s[m]];
        for (const auto & ch : left) {
            if (right[ch] > 0)  {
                seen.insert({s[m],ch});
            }
        }
        left.insert(s[m]);
    }
    return seen.size(); 

    }
};