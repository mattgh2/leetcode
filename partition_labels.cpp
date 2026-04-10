#include <string>
#include <vector>
#include <iostream>
auto good(std::string s) -> std::vector<int> {
    int n = s.length();
    int freq[26] = {0};
    for (int i = 0; i < n; ++i) {
        ++freq[s[i]-97];
    }
    std::vector<int> ans;
    int last = 0;
    for (int i = 0, j = 1; i < n;) {

        if (i == j) {
            ans.push_back(j - last);
            ++j, last = i;
        }
        else {
            int ch = s[i]-97;
            if (i == last && freq[ch] > 0) --freq[ch];
            while (freq[ch] > 0) {
                --freq[s[j++]-97];
            }
            ++i;
        }
    }
    ans.push_back(n - last);
    return ans;
}

int main(int argc, char **argv){

    
    std::string s = "eccbbbbdec";
    auto g = good(s);
    for (const auto &a : g) {
        std::cout << a << '\n';
    }


    return 0;
}
