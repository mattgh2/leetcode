#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> vii;
typedef std::vector<int> vi;

auto fn(int n, vii& rectangles) -> bool { 
    int m = rectangles.size();

    std::vector<std::pair<int,int>> v;
    std::vector<std::pair<int,int>> h;

    for (int i = 0; i < m; ++i) {
        v.push_back({rectangles[i][1], rectangles[i][3]});
        h.push_back({rectangles[i][0], rectangles[i][2]});
    }

    std::ranges::sort(v);
    std::ranges::sort(h);

    std::vector<std::pair<int,int>> v_intervals;
    int left = v[0].first, right = v[0].second;
    for (int i = 1; i < v.size(); ++i) {
        auto [l, r] = v[i];
        if (l < right) {
            if (r >= right) {
                right = r;
            }
        }
        else {
            v_intervals.push_back({left,right});
            left = l;
            right = r;
        }
    }
    v_intervals.push_back({left,right});

    std::vector<std::pair<int,int>> h_intervals;
    left = h[0].first, right = v[0].second;
    for (int i = 1; i < h.size(); ++i) {
        auto [l, r] = h[i];
        if (l < right) {
            if (r >= right) {
                right = r;
            }
        }
        else {
            h_intervals.push_back({left,right});
            left = l;
            right = r;
        }
    }
    h_intervals.push_back({left,right});
    return v_intervals.size() >= 3 || h_intervals.size() >= 3;

}
int main(int argc, char **argv){

    vii v = {
        {1,0,5,2},
        {0,2,2,4},
        {3,2,5,3},
        {0,4,4,5}
    };
    
    std::cout << fn(5, v);


    return 0;
}
