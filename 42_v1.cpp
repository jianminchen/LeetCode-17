/*
  42_v1.cpp
  Trapping Rain Water
*/

class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    int leftMax[n], rightMax[n];
    int maxVal = height[0];
    for (int i = 1; i < n; i++) {
      leftMax[i] = maxVal;
      maxVal = max(maxVal, height[i]);
    }
    maxVal = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      rightMax[i] = maxVal;
      maxVal = max(maxVal, height[i]);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      int maxVal = min(leftMax[i], rightMax[i]);
      if (maxVal > height[i]) ans += (maxVal - height[i]);
    }
    return ans;
  }
};