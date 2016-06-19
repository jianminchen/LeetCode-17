/*
  264_v1.cpp
  Ugly Number II
*/

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> uglyNumbers(n, 0);
    uglyNumbers[0] = 1;
    vector<int> ptrs{0, 0, 0};
    for (int i = 1; i < n; i++) {
      int min2 = uglyNumbers[ptrs[0]] * 2;
      int min3 = uglyNumbers[ptrs[1]] * 3;
      int min5 = uglyNumbers[ptrs[2]] * 5;
      int minVal = min(min(min2, min3), min5);
      uglyNumbers[i] = minVal;
      if (min2 == minVal) ptrs[0]++;
      if (min3 == minVal) ptrs[1]++;
      if (min5 == minVal) ptrs[2]++;
    }
    return uglyNumbers[n - 1];
  }
};