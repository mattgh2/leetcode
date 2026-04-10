
#include <vector>
#include <iostream>
#include <string>

auto solve(std::string &s, int l, int r, bool skipped) -> bool {
    int n = s.size();

    while (l < r) {
        if (s[l] != s[r]) {
            if (!skipped) {
                return solve(s, l + 1, r, true) || solve(s, l, r - 1, true);
            }
            else {
                return false;
            }
        }
        ++l, --r;
    }
    return true;
}
auto fn(std::string s) -> bool {
    int n = s.length();

    return solve(s, 0, n-1,false);

}

int main(int argc, char **argv){
    std::string s = "abca";
    std::string s2 = "abc";
    std::string s3 = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    
    
    // std::cout << std::boolalpha << fn(s) << '\n';
    std::cout << std::boolalpha << fn(s) << '\n';
    std::cout << std::boolalpha << fn(s2) << '\n';
    std::cout << std::boolalpha << fn(s3) << '\n';


    return 0;
}
