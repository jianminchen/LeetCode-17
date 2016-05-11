/*
  346_v1.cpp
  Moving Average from Data Stream
*/

class MovingAverage {
  queue<int> q;
  int sum, maxSize;

 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    while (!q.empty()) q.pop();
    sum = 0;
    maxSize = size;
  }

  double next(int val) {
    if (q.size() == maxSize) {
      sum -= q.front();
      q.pop();
    }
    q.push(val);
    sum += val;
    return 1.0 * sum / q.size();
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */