/*
  123_v1.cpp
  Best Time to Buy and Sell Stock III
*/

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    int f[n][3], maxDiff[2];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < 2; i++) maxDiff[i] = -prices[0];
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= 2; j++) {
        f[i][j] = max(f[i - 1][j], prices[i] + maxDiff[j - 1]);
        // printf("f[%d][%d] = %d\n", i, j, f[i][j]);
      }
      for (int j = 0; j <= 1; j++)
        maxDiff[j] = max(maxDiff[j], f[i][j] - prices[i]);
    }
    return max(max(f[n - 1][0], f[n - 1][1]), f[n - 1][2]);
  }
};