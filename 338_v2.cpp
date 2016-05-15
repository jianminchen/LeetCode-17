/*
  338_v2.cpp
  Counting Bits
*/

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ret;
    for (int i = 0; i <= num; i++) {
      if (i == 0)
        ret.push_back(0);
      else if (i == 1)
        ret.push_back(1);
      else
        ret.push_back(ret[i / 2] + (i & 1));
    }
    return ret;
  }
};