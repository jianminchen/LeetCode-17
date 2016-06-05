/*
  322_v1.cpp
  Coin Change
*/

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> f(amount + 1, INT_MAX);
    f[0] = 0;
    for (int i = 0; i < coins.size(); i++) {
      for (int j = 0; j + coins[i] <= amount; j++) {
        if (f[j] != INT_MAX) f[j + coins[i]] = min(f[j + coins[i]], f[j] + 1);
      }
    }
    if (f[amount] == INT_MAX) return -1;
    return f[amount];
  }
};