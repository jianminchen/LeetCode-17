/*
  188_v1.cpp
  Best Time to Buy and Sell Stock IV

  This is still a O(nk) algorithm except that when k >= n / 2 we now only need
  O(n) to solve the original problem. My previous solution TLEed because I
  didn't get this special case and thought about optimizing the complexity of
  the DP part.

  In fact in my first set of submissions, I used a slightly different DP
  relationship:

  f[i][j][0] indicates we are at the end of day i, we've made j transactions and
  0 indicates the jth transaction was not done on day i, similarly, f[i][j][1]
  indicates the transaction was performed on the i-th day.

  Therefore, the relationship becomes:
  f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
  f[i][j][1] = max(f[i - 1][j - 1][0], f[i - 1][j][1]) + prices[i] - prices[i -
  1];

  Here the tricky part is the how f[i - 1][j][1] leads to f[i][j][1], well,
  since we've done two consecutive transactions on day i - 1 and day i, we can
  immediately group these two and consider them as one transaction.
*/

class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    if (k >= n / 2) {
      int ans = 0;
      for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
      }
      return ans;
    }
    int f[n][k + 1], maxDiff[k];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < k; i++) maxDiff[i] = -prices[0];
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= k; j++)
        f[i][j] = max(f[i - 1][j], prices[i] + maxDiff[j - 1]);
      for (int j = 0; j < k; j++)
        maxDiff[j] = max(maxDiff[j], f[i][j] - prices[i]);
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) ans = max(ans, f[n - 1][i]);
    return ans;
  }
};