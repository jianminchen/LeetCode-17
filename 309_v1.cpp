/*
  309_v1.cpp
  Best Time to Buy and Sell Stock with Cooldown
*/

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;
    int f[n][2];
    memset(f, 0, sizeof(f));
    int maxVal = -prices[0];
    for (int i = 1; i < n; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1]);
      f[i][1] = prices[i] + maxVal;
      maxVal = max(maxVal, -prices[i] + f[i - 1][0]);
    }
    return max(f[n - 1][0], f[n - 1][1]);
  }
};