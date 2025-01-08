class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() > words[j].size())
                    continue;
                std::string current_word = words[i];
                int pp = words[j].size() - words[i].size() ;
                if (words[j].substr(0, current_word.size()) == current_word &&
                    words[j].substr(pp) == current_word) {
                        ++ans;
                    }
            }
        }


        return ans;
    }
};