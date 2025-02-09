class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            int n = groups.size(), m = elements.size();    
    
    int N = 100'001;

    std::vector<int> div(N, -1);

    for (int i = 0; i < m; ++i) {
        if (div[elements[i]] == -1) {
            div[elements[i]] = i;
        }
    }

    std::vector<int> ans(n,-1);

    for (int i = 0; i < n; ++i) {
        int idx = -1; 
        for (int j = 1; j * j <= groups[i]; ++j) {
            if (groups[i] % j != 0) continue;
            int tmp = -1;
            if (div[j] != -1 && div[groups[i] / j] != -1) {
                tmp = std::min(div[j], div[groups[i] / j]);
            }
            else if (div[j] != -1 || div[groups[i] / j] != -1){
                tmp = (div[j] != -1) ? div[j] : div[groups[i] / j];
            }
            else { continue; }

            if (idx == -1) {
                idx = tmp;
            }
            else {
                idx = std::min(idx, tmp);
            }
        }
        ans[i] = idx;
    }

    return ans;

    }
};