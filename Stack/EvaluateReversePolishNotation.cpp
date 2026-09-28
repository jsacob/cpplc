#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {

    std::stack<std::string> stack = {};

    std::unordered_set<std::string> operators = {"+", "-", "*", "/"};

    for (std::string token : tokens) {

      if (operators.contains(token)) {

        int a = std::stoi(stack.top());
        stack.pop();
        int b = std::stoi(stack.top());
        stack.pop();

        std::string result;

        if (token == "+")
          result = b + a;
        if (token == "-")
          result = b - a;
        if (token == "*")
          result = b * a;
        if (token == "/")
          result = b / a;

        stack.push(result);

      } else {
        stack.push(token);
      }
    }

    return 0;
  };
};

int main() {
  Solution sol;
  std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
  std::cout << sol.evalRPN(tokens);
};

// Keeping this one because of the insane overhead I created as a reference to evalRPN2. Also bad practice to constantly be converting types and this code is ugly too.
