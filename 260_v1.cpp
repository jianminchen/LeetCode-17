/*
  260_v1.cpp
  Single Number III
*/

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int val = 0;
    for (int i = 0; i < nums.size(); i++) val ^= nums[i];
    int bitTest = 0;
    for (int i = 0; i < 32; i++) {
      if (val & (1 << i)) {
        bitTest = (1 << i);
        break;
      }
    }
    int num1 = 0, num2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] & bitTest)
        num1 ^= nums[i];
      else
        num2 ^= nums[i];
    }
    return vector<int>{num1, num2};
  }
};