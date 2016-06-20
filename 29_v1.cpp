/*
  29_v1.cpp
  Divide Two Integers
*/

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    bool isNegative = (dividend < 0) ^ (divisor < 0);
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    long long _dividend = llabs(dividend);
    long long _divisor = llabs(divisor);
    int sum = 0;
    while (_dividend >= _divisor) {
      int tmp = 1;
      long long _d = _divisor;
      while (_dividend >= (_d << 1)) {
        _d <<= 1;
        tmp <<= 1;
      }
      sum += tmp;
      _dividend -= _d;
    }
    if (isNegative) sum = -sum;
    return sum;
  }
};