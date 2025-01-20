class Solution {
public:
    typedef std::pair<int,int> ii;
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        std::vector<ii> p(n*m + 1);
        std::vector<int> painted(n*m + 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[mat[i][j]] = {i,j};
            }
        }
        for (int i = 0; i < arr.size(); ++i)  {
            auto & [row,col] = p[arr[i]];
            ++painted[row];
            ++painted[col + n];
            if (painted[row] == m || painted[col + n] == n) return i;
        }
        return -1;
    }
};