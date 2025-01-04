class Solution {
    typedef std::pair<int,int> ii;
public:
    int maxScore(string s) {
           std::vector<ii> pre(s.length());
    pre[0]  = (s[0] == '1') ? std::make_pair(0,1) : std::make_pair(1,0);

    for (int i = 1; i < s.length(); ++i) {
        ii x = pre[i-1];
        if (s[i] == '0') {
            x.first++;
        }
        else {
            x.second++;
        }
        pre[i] = x;
    }
    int ans = 0;
    for (int i = 1; i < s.length(); ++i) {
        int l = pre[i-1].first;
        int r = pre[s.length() - 1].second - pre[i - 1].second;
        int score = l + r;
        ans = std::max(ans, score);
    }

    return ans;
 
    }
};