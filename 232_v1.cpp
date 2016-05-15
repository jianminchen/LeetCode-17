/*
  232_v1.cpp
  Implement Queue using Stacks
*/

class Queue {
  stack<int> s1, s2;

  void reverseOrder() {
    if (s2.empty()) {
      while (!s1.empty()) {
        int val = s1.top();
        s1.pop();
        s2.push(val);
      }
    }
  }

 public:
  // Push element x to the back of queue.
  void push(int x) { s1.push(x); }

  // Removes the element from in front of queue.
  void pop(void) {
    reverseOrder();
    s2.pop();
  }

  // Get the front element.
  int peek(void) {
    reverseOrder();
    return s2.top();
  }

  // Return whether the queue is empty.
  bool empty(void) { return s1.empty() && s2.empty(); }
};