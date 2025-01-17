class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int window_size = s1.size();
        int n = s2.size();
        int a[26] = {0};
        int b[26] = {0};
        for (int i = 0; i < window_size; ++i) {
            ++a[s1[i] - 97];
            ++b[s2[i] - 97];
        }
        bool ok = true;
        for (int i = 0; i < 26 && ok; ++i) {
            if (b[i] != a[i])
                ok = false;
        }
        if (ok)
            return true;

        for (int r = window_size; r < n; ++r) {
            --b[s2[r - window_size] - 97];
            ++b[s2[r] - 97];
            ok = true;
            for (int i = 0; i < 26 && ok; ++i) {
                if (b[i] != a[i])
                    ok = false;
            }
            if (ok)
                return true;
        }
        return false;
    }
};