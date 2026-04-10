#include <string>
#include <vector>
#include <iostream>

auto fn(std::string blocks, int k) -> int {
    int white{}; int min = 0;
    for (int i = 0; i < k; ++i) {
        if (blocks[i] == 'W') ++white;
    }
    min = white;
    for (int i = k; i < (int)blocks.size(); ++i) {
        if (blocks[i - k] == 'W') --white;
        if (blocks[i] == 'W') ++white;
        min = std::min(min, white); 
    }
    return min;

}

int main(int argc, char **argv){


    std::string s = "WBBWWBBWBW";
    int k = 7;
    std::cout << fn(s, k);
    


    return 0;
}
