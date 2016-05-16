/*
  343_v1.cpp
  Integer Break

  Made a typo in my first submission.
*/

class Solution {
 public:
  int integerBreak(int n) {
    int ret = 1;
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n % 3 == 0) {
      for (int i = 0; i < n / 3; i++) ret *= 3;
    } else if (n % 3 == 1) {
      for (int i = 0; i < n / 3 - 1; i++) ret *= 3;
      ret *= 4;
    } else if (n % 3 == 2) {
      for (int i = 0; i < n / 3; i++) ret *= 3;
      ret *= 2;
    }
    return ret;
  }
};