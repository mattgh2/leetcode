class Solution {
public:
    typedef std::vector<std::vector<int>> vii;
    typedef std::vector<int> vi;
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        std::vector<int> ans(queries.size());
        
        const int N = heights.size();
        const int P = log2(N);

        vii st(P+1, std::vector<int>(N));
        vii it(P+1, std::vector<int>(N));
        vi lg(N+1);

        for (int i = 0; i < N; ++i) {
            st[0][i] = heights[i];
            it[0][i] = i;
        }
        for (int i = 2; i <= N; ++i) {
            lg[i] = lg[i/2] + 1;
        }

        for (int p = 1; p <= P; ++p) {
            long l{}, r{};
            for (int i = 0; i + (1 << p) <= N; ++i) {
                l = st[p-1][i];
                r = st[p-1][i+(1<<(p-1))];

                st[p][i] = std::max(l,r);

                if (l >= r) {
                    it[p][i] = it[p-1][i];
                } else {
                    it[p][i] = it[p-1][i+(1<<(p-1))];
                }
            }

        }
        auto go = [&lg, &st, &it](int l, int r) -> std::pair<int,int> {
            int len = r - l + 1;
            int p = lg[len];
            
            int left = st[p][l];
            int right = st[p][r-(1<<p)+1];

            if (left > right) return std::make_pair(left, it[p][l]);
            else return std::make_pair(right, it[p][r-(1<<p)+1]);

        };

        size_t k = 0;
        for (auto & query : queries) {

            std::ranges::sort(query);
            int mx = std::max(heights[query[0]], heights[query[1]]);

            if (query[0] == query[1] || (heights[query[0]] != heights[query[1]] && mx == heights[query[1]])) {
                ans[k++] = query[1];
                continue;
            }

            int l = query[1];
            int r = N - 1;

            std::pair<int,int> best = {-1,-1};
            while (l <= r)  {
                int mid = l + (r-l) / 2;
                [[maybe_unused]] auto [a, b] = go(l,mid);
                if (a > mx) {
                    best = {a,b};
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (best.first == -1) ans[k++] = -1;
            else ans[k++] = best.second;

        }

        return ans;
    }

};


