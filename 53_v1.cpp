/*
  53_v1.cpp
  Maximum Subarray
*/

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size(), dp = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
      dp = max(nums[i], dp + nums[i]);
      ans = max(ans, dp);
    }
    return ans;
  }
};