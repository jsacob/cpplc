#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (stack.empty() || stack.top() != closeToOpen[c]) {
                    return false;
                }
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};

int main() {
    std::string s = "({[]})";
    Solution solution;
    std::cout << (solution.isValid(s) ? "true" : "false") << std::endl;

    return 0;
}
