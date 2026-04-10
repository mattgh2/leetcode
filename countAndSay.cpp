
#include <string>
#include <iostream>
#include <vector>

auto solve(int n) -> std::string {
    std::vector<std::string> t(n+1);

    t[1] = "1";
    for (int i = 2; i <= n; ++i)  {
        int count = 1;
        for (int j = 1; j < t[i-1].size(); ++j) {
            if (t[i-1][j-1] == t[i-1][j]) { 
                ++count;
            }
            else {
                t[i] += std::to_string(count) + std::to_string(t[i-1][j-1]-48); 
                count = 1;
            }
        }
        t[i] += std::to_string(count) + std::to_string(t[i-1].back()-48); 

    }

    return t[n];
    


}
int main(int argc, char **argv){

    
    int n  = 4;
    solve(n);


    return 0;
}
