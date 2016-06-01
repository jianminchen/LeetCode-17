/*
  152_v1.cpp
  Maximum Product Subarray
*/

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<int> maxP(nums.size(), 0);
    vector<int> minP(nums.size(), 0);
    maxP[0] = minP[0] = nums[0];
    int ans = maxP[0];
    for (int i = 1; i < nums.size(); i++) {
      maxP[i] = max(max(maxP[i - 1] * nums[i], minP[i - 1] * nums[i]), nums[i]);
      minP[i] = min(min(maxP[i - 1] * nums[i], minP[i - 1] * nums[i]), nums[i]);
      ans = max(ans, maxP[i]);
    }
    return ans;
  }
};