/*
  202_v1.cpp
  Happy Number
*/

class Solution {
 public:
  int transform(int n) {
    int ret = 0;
    while (n) {
      ret += (n % 10) * (n % 10);
      n /= 10;
    }
    return ret;
  }
  bool isHappy(int n) {
    unordered_set<int> nums;
    nums.insert(n);
    while (true) {
      n = transform(n);
      if (n == 1) return true;
      if (nums.find(n) != nums.end()) return false;
      nums.insert(n);
    }
    return true;
  }
};