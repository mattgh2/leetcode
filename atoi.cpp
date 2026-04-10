#include <iostream>
#include <vector>
#include <climits> 
const long long MIN = 1 << 31;

auto fun(std::string s) -> int {
    int n = s.size();

    int ans = 0, sign = 1; 
    bool ok = false;
    // Handle case for floating point.
    for (int i = 0; i < n; ++i) {
        if (s[i] == 32) {
            continue;
        }

        else if (s[i] == '-' || s[i] == '+') {
            if (ok) {
                break;
            }
            else {
                sign = (s[i] == '-') ? -1 : 1;
            }
            ok = true;
        }
        else if (s[i] < 48 || s[i] > 57) {
            break;
        }
        else {
            ok = true;
            int digit = s[i]-48;
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit; 
        }
    }
    return ans * sign;
}

int main(int argc, char **argv){

    
    std::string s = "-042";
    std::string s3 = "3.14159";
    std::string s2 = "1337c0d3";

    std::cout << fun(s3);


    return 0;
}
