/*
  7_v1.cpp
  Reverse Integer
*/

class Solution {
 public:
  int reverse(int x) {
    if (x == INT_MIN) return 0;
    if (x < 0) return -reverse(-x);
    int ans = 0;
    while (x) {
      if ((INT_MAX - x % 10) / 10 < ans) return 0;
      ans = ans * 10 + x % 10;
      x /= 10;
    }
    return ans;
  }
};