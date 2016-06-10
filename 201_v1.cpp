/*
  201_v1.cpp
  Bitwise AND of Numbers Range

  My approaches for the first two submissions were completely wrong for this
  problem.
*/

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int ret = 0;
    for (int i = 31; i >= 0; i--) {
      int val1 = (m & (1 << i));
      int val2 = (n & (1 << i));
      if (val1 && val2)
        ret |= (1 << i);
      else {
        if (val1 != val2) break;
      }
    }
    return ret;
  }
};