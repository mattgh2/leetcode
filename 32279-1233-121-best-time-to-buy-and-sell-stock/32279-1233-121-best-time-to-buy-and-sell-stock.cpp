class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), max = 0;
        int l = 0, r = l + 1;
        while (r < n) {
            max = std::max(max, prices[r] - prices[l]);
            if (prices[r] < prices[l]) l = r;
            ++r;
        }
        
        return max;
    }
};