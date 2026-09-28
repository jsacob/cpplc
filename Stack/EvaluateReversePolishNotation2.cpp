#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {

    std::stack<int> stack = {};
    std::unordered_set<std::string> operators = {"+", "-", "*", "/"};

    for (std::string token : tokens) {

      if (operators.contains(token)) {
          int a = stack.top(); stack.pop();
          int b = stack.top(); stack.pop();

          if(token == "+") stack.push(b+a);
          else if(token == "-") stack.push(b-a);
          else if(token == "*") stack.push(b*a);
          else if(token == "/") stack.push(b/a);


      } else {
        stack.push(std::stoi(token));
      }
    };
    return stack.top();
  };
};

int main() {
  Solution sol;
  std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
  std::cout << sol.evalRPN(tokens);
};
