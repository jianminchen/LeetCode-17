/*
  155_v1.cpp
  Min Stack
*/

class MinStack {
 public:
  stack<int> s, minS;
  /** initialize your data structure here. */
  MinStack() {
    while (!s.empty()) s.pop();
    while (!minS.empty()) minS.pop();
  }

  void push(int x) {
    s.push(x);
    if (minS.empty() || minS.top() >= x) minS.push(x);
  }

  void pop() {
    if (!minS.empty() && s.top() == minS.top()) minS.pop();
    s.pop();
  }

  int top() { return s.top(); }

  int getMin() { return minS.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */