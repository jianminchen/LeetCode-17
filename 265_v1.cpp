/*
  265_v1.cpp
  Paint House II
*/

class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    int k = costs[0].size();
    int dp[n][k], leftMin[n][k], rightMin[n][k];
    for (int i = 0; i < k; i++) dp[0][i] = costs[0][i];
    int minVal = dp[0][0];
    for (int i = 1; i < k; i++) {
      leftMin[0][i] = minVal;
      minVal = min(minVal, dp[0][i]);
    }
    minVal = dp[0][k - 1];
    for (int i = k - 2; i >= 0; i--) {
      rightMin[0][i] = minVal;
      minVal = min(minVal, dp[0][i]);
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < k; j++) {
        int minCost;
        if (j == 0)
          minCost = rightMin[i - 1][0];
        else if (j == k - 1)
          minCost = leftMin[i - 1][k - 1];
        else
          minCost = min(leftMin[i - 1][j], rightMin[i - 1][j]);
        dp[i][j] = minCost + costs[i][j];
      }
      int minVal = dp[i][0];
      for (int j = 1; j < k; j++) {
        leftMin[i][j] = minVal;
        minVal = min(minVal, dp[i][j]);
      }
      minVal = dp[i][k - 1];
      for (int j = k - 2; j >= 0; j--) {
        rightMin[i][j] = minVal;
        minVal = min(minVal, dp[i][j]);
      }
    }
    int ans = dp[n - 1][0];
    for (int i = 1; i < k; i++) ans = min(ans, dp[n - 1][i]);
    return ans;
  }
};