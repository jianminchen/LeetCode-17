/*
  268_v1.cpp
  Missing Number
*/

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size(), sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    return ((long long)n * (n + 1) / 2 - sum);
  }
};