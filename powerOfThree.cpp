
#include <iostream>
#include <vector>
#include <cmath>

auto fn(int n) -> bool {
    int P = std::log10(n) / std::log10(3);

    for (int i = P; i >= 0; --i) { 
        if (pow(3,i) <= n) {
            n -= pow(3,i);
        }
    }
    return n == 0;

}

int main(int argc, char **argv){

    int n = 27;

    std::cout << fn(81) << '\n';
    std::cout << fn(12) << '\n';
    std::cout << fn(21) << '\n';
    std::cout << fn(91) << '\n';


    return 0;
}
