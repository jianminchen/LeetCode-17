/*
  338_v1.cpp
  Counting Bits
*/

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ret;
    for (int i = 0; i <= num; i++) {
      int n = i, cnt = 0;
      while (n) n = n & (n - 1), cnt++;
      ret.push_back(cnt);
    }
    return ret;
  }
};