/*
  213_v1.cpp
  House Robber II
*/

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int dp[n][2][2] = {0};
    dp[0][0][1] = dp[0][1][0] = -1;
    dp[0][1][1] = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
      dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);
      dp[i][1][0] = dp[i - 1][0][0];
      if (dp[i - 1][0][0] != -1) dp[i][1][0] = dp[i - 1][0][0] + nums[i];
      dp[i][1][1] = dp[i - 1][0][1];
      if (dp[i - 1][0][1] != -1) dp[i][1][1] = dp[i - 1][0][1] + nums[i];
    }
    return max(dp[n - 1][0][0], max(dp[n - 1][0][1], dp[n - 1][1][0]));
  }
};