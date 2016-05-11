/*
  121_v1.cpp
  Best Time to Buy and Sell Stock

  My first submission got WA since I've initialized ans as INT_MIN but this is
  incorrect as we do not need to do any transaction so at least ans can be zero.
*/

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int minVal = prices[0], ans = 0;
    for (int i = 1; i < prices.size(); i++) {
      ans = max(ans, prices[i] - minVal);
      minVal = min(minVal, prices[i]);
    }
    return ans;
  }
};