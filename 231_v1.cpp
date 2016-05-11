/*
  231_v1.cpp
  Power of Two

  My first submission got WA since I did not add an additional pair of
  parentheses between "n & (n - 1) == 0".
*/

class Solution {
 public:
  bool isPowerOfTwo(int n) { return n > 0 && ((n & (n - 1)) == 0); }
};