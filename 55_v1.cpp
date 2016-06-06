/*
  55_v1.cpp
  Jump Game
*/

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.size() == 0) return false;
    int maxIdx = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (maxIdx >= i && i + nums[i] > maxIdx)
        maxIdx = max(maxIdx, i + nums[i]);
    }
    return maxIdx >= nums.size() - 1;
  }
};