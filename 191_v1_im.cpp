/*
  191_v1_im.cpp
  Number of 1 Bits
*/

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
      n &= (n - 1);
      cnt++;
    }
    return cnt;
  }
};