class Solution {
public:
    typedef std::vector<std::vector<int>> vii;
    typedef std::pair<int, int> ii;
    std::vector<int> vowelStrings(std::vector<std::string>& words,
                                  vii& queries) {
        const int n = words.size();
        const std::unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        std::vector<int> ans(queries.size());

        auto good = [&words, &n, &s](const std::string& word) -> bool {
            auto size = word.length();
            return (s.find(word[0]) != s.end() &&
                    s.find(word[size - 1]) != s.end());
        };

        std::vector<int> pre(n, 0);
        pre[0] = good(words[0]) ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            bool ok = good(words[i]);
            pre[i] = ok ? 1 + pre[i - 1] : pre[i - 1];
        }
        unsigned int i = 0;
        for (const auto& v : queries) {
            int l = v[0], r = v[1];
            ans[i++] = (l > 0) ? pre[r] - pre[l - 1] : pre[r];
        }

        return ans;
    }
};
