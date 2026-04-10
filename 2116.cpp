#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
   bool canBeValid(std::string s, std::string locked)  {

       int n = s.size();
       if (n % 2) return false;
    
        std::stack<int> locked_stack;
        std::stack<int> unlocked_stack;

        for (int i = 0; i < n; ++i) {
            if (locked[i] == 0) unlocked_stack.push(i);
            else if (s[i] == '(') locked_stack.push(i);
            else {
                if (!locked_stack.empty()) {
                    locked_stack.pop();
                }
                else if (!unlocked_stack.empty()) {
                    unlocked_stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        while (!locked_stack.empty() && locked_stack.top() < unlocked_stack.top()) {
            locked_stack.pop();
            unlocked_stack.pop();
        }
        if (locked_stack.size() > 0) return false;

        return unlocked_stack.size() % 2 == 0 ? true : false;
                
   }

};
int main(int argc, char **argv){

    
    std::string s = "()))";
    std::string locked = "0010";
    std::string s2 = "))())";
    std::string locked2 = "010100";
    // (())))
    // (()) ()

    Solution sol;
    std::cout << std::boolalpha << sol.canBeValid(s,locked);
    return 0;
}
