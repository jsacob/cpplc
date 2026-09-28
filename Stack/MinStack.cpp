#include <iostream>
#include <stack>

class MinStack {
public:
  std::stack<int> stack;

  MinStack() {}

  void push(int value) { stack.push(value); }

  void pop() { stack.pop(); }

  int top() { stack.top(); }

  int getMin() {}
};

int main() {

  MinStack ms;

  ms.push(-2);
  ms.push(4);
  ms.pop();
  ms.top();

  return 0;
}
