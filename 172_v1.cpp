/*
  172_v1.cpp
  Factorial Trailing Zeroes
*/

class Solution {
 public:
  int trailingZeroes(int n) {
    int ret = 0;
    long long curr = 5;
    while (n / curr) {
      ret += n / curr;
      curr *= 5;
    }
    return ret;
  }
};