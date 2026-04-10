#include <vector>
#include <iostream>
#include <climits>
typedef std::vector<std::vector<int>> vii;
typedef std::vector<int> vi;

auto fn(int days, std::vector<std::vector<int>> &meetings) -> int { 
    int n = meetings.size();
    vii merged;

    auto comp = [](const auto &a, const auto &b) -> bool {
        return a[0] < b[0]; 
    };
    std::sort(meetings.begin(), meetings.end(), comp);

    int left = meetings[0][0], right = meetings[0][1];

    for (int i = 1; i < n; ++i) {
        vi& c = meetings[i];
        if (c[0] <= right) {
            if (c[1] >= right) {
                right = c[1];
            }
        }
        else {
            merged.push_back({left,right});
            left = c[0];
            right = c[1];
        }
    }

    merged.push_back({left,right});
    int ans = days;
    n = merged.size();

    for (int i = 0; i < n; ++i) {
        ans -= merged[i][1] - merged[i][0] + 1;
    }
    return ans;

}
auto merge(std::vector<std::vector<int>> &intervals) -> std::vector<std::vector<int>> {
    int n = intervals.size();

    auto comp = [](const auto &a, const auto &b) -> bool {
        return a[0] < b[0]; 
    };

    std::sort(intervals.begin(), intervals.end(), comp);
    int left = intervals[0][0], right = intervals[0][1];
    std::vector<std::vector<int>> ans;
    for (int i = 1; i < n; ++i) {
        std::vector<int> &c = intervals[i];
        if (c[0] <= right) {
            if (c[0] >= right) {
                right = c[1];
            }
        }
        else {
            ans.push_back({left,right});
            left = c[0];
            right = c[1];
        }
    }
    ans.push_back({left, right});
    return ans;

}
int main(int argc, char **argv){

     
    std::vector<std::vector<int>> meetings = {
        {5,7},
        {1,3},
        {9,10}
    };




    std::cout << fn(10, meetings);



    return 0;
}
