#include <iostream>
#include <vector>
std::vector<std::string> A;

auto permute(int K,  std::string &&current) -> void {
    if (K == 0) {
        A.push_back(current);
        return;
    }

    for (int i = 97; i < 100; ++i) {
        if (K > 0 && current.back() == char(i)) {
            continue;
        }
        current.push_back(i);

        permute(K - 1, std::move(current));
        current.pop_back();
    }
}

auto fn(int n, int k) -> std::string {
    A = std::vector<std::string>();

    permute(n, "");

    return (k > A.size()) ? "" : A[k-1];
}

int main(int argc, char **argv){


    std::cout <<fn(1,3);

    return 0;
}
