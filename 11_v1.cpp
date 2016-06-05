/*
  11_v1.cpp
  Container With Most Water
*/

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    int l = 0, r = n - 1, ans = 0;
    while (l < r) {
      int tmp = min(height[r], height[l]) * (r - l);
      ans = max(ans, tmp);
      if (height[l] <= height[r])
        l++;
      else
        r--;
    }
    return ans;
  }
};