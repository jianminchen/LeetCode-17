/*
  238_v1.cpp
  Product of Array Except Self
*/

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size(), left[n], right[n];
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) left[i] = left[i - 1] * nums[i];
    for (int i = n - 2; i >= 0; i--) right[i] = right[i + 1] * nums[i];
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      int l = i - 1 >= 0 ? left[i - 1] : 1;
      int r = i + 1 < n ? right[i + 1] : 1;
      ret.push_back(l * r);
    }
    return ret;
  }
};