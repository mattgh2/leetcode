#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <algorithm>
#include <iostream>


class Solution {

public:
    typedef std::vector<std::vector<std::string>> vvs;
    struct array_compare {
        
        auto operator()(const std::array<int,26> &arr) const -> size_t {
            std::size_t hash_value = 0;

            for (const auto &i : arr) {
                hash_value ^= std::hash<int>()(i) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
            }
            return hash_value;
        }

    };
    vvs groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::array<int,26>, std::vector<std::string>, array_compare> mp;
        for (const auto &str : strs) {
            std::array<int,26> count = {};
            for (const char &ch : str)  {
                ++count[ch - 'a'];
            }
            mp[count].push_back(str);
        }
        vvs result(mp.size());
        size_t n{};
        std::hash<int>{}(1);
        for (const auto &pair : mp) {
            std::for_each(pair.second.begin(), pair.second.end(), [&n,&result](const std::string &str) {
                result[n].push_back(str);
            });
            ++n;
        }

        return result;
    }

};
int main(int argc, char **argv){

    std::vector<std::string> v = {"act", "pots", "cat", "stop", "hat"};
    Solution solution;

    auto res = solution.groupAnagrams(v);


    for (const auto &arr : res) {
        for (const auto &str : arr) {
            std::cout << str << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
