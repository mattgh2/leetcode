class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (derived[i]) {
                last = ~last;
            }
        }
        return last == 0;
    }
};