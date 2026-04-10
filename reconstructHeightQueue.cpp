
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<std::vector<int>> vii;

auto fn(vii & people) -> vii {
    auto comp = [](const std::vector<int> &a, const std::vector<int> &b) -> bool { return a[0] < b[0]; }; 
    int n = people.size();
    std::sort(people.begin(), people.end(),comp);

    vii ans(n);
    for (int i = 0; i < n; ++i) {
        int height = people[i][0], ahead = people[i][1];

        if (ans[ahead].empty()) {
            ans[ahead] = people[i];
        }
        else {
            int j = ahead;
            while (!ans[ahead].empty()){
                ++j;
            }
            ans[j] = people[i];
        }
    }
    return ans;



}

int main(int argc, char **argv){

    
    vii v = {
        {7,0},
        {4,4},
        {7,1},
        {5,0},
        {6,1},
        {5,2}
    };
    auto ans = fn(v);
    for (const auto &v : ans) {
        std::cout << "[" << v[0] << ',' << v[1] << "]" << '\n';
    }

    return 0;
}
