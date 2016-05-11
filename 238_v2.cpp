/*
  238_v2.cpp
  Product of Array Except Self
*/

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret;
    ret.push_back(1);
    int tmp = 1, n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      tmp *= nums[i];
      ret.push_back(tmp);
    }
    tmp = 1;
    for (int i = n - 1; i >= 0; i--) {
      ret[i] *= tmp;
      tmp *= nums[i];
    }
    return ret;
  }
};