
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::unordered_set<std::string> B;

auto solve(int k, std::string &current) ->  std::string {
    if (k == 0) {

        if (B.find(current) == B.end()) {
            return current;
        }
        return "";
    }

    for (int i = 48; i < 50; ++i) {
        current.push_back(i);
        auto solstr = solve(k -1, current);
        if (solstr.length()) {
            return solstr;
        }
        current.pop_back();
    }
    return "";

}

auto fn(std::vector<std::string> &nums) -> std::string {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        B.insert(nums[i]);
    }

    std::string s;
    return solve(n, s);
}

int main(int argc, char **argv){

    std::vector<std::string> v = {
        "01",
        "10",
    };

    std::cout << fn(v) << '\n';

    

    return 0;
}
