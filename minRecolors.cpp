#include <iostream>
#include <string>
#include <vector>
#include <climits>

int best = INT_MAX;
auto count(const std::string &blocks) -> int {
    int acc = 0, ret = 0;
    for (int i = 0; i < (int)blocks.size();++i) {
        if (blocks[i] == 'B') ++acc;
        else {
            ret = std::max(ret, acc);
            acc = 0;
        }
    }
    return std::max(ret,acc);
}

auto go(int i, int P, std::string blocks, int k) -> void {
    if (count(blocks) >= k || i >= (int)blocks.size()) {
        if (count(blocks) >= k) {
            best = std::min(best, P);
        }
        return;
    }

   for (; i < (int)blocks.size() && blocks[i] == 'B'; ++i);

   blocks[i] = 'B';
   go(i + 1, P + 1, blocks, k);
   blocks[i] = 'W';
   go(i + 1, P, blocks, k);
}

auto fn(std::string blocks, int k) -> int {

    int n = blocks.size();
    go(0, 0, blocks,k);
    return best;
}
int main(int argc, char **argv){
    

    std::string s = "WBB";
    int k = 1;
    std::cout << fn(s,k);

    


    return 0;
}
