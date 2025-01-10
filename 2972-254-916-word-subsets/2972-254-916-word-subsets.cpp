class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        std::vector<std::string> ans;

        std::vector<int> max_freq(26, 0);
        for (const auto& word : words2) {
            std::vector<int> p(26, 0);
            for (int i = 0; i < word.size(); ++i) {
                ++p[word[i] - 'a'];
            }
            for (int k = 0; k < 26; ++k) {
                max_freq[k] = std::max(max_freq[k], p[k]);
            }
        }

        for (int i = 0; i < n; ++i) {
            std::vector<int> freq(26);
            for (int j = 0; j < words1[i].size(); ++j) {
                ++freq[words1[i][j] - 'a'];
            }
            bool ok = true;
            for (int k = 0; k < 26 && ok == true; ++k) {
                if (freq[k] < max_freq[k])
                    ok = false;
            }
            if (ok)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};