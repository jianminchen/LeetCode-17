/*
  137_v1.cpp
  Single Number II
*/

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int cnt[32] = {0};
    for (int i = 0; i < nums.size(); i++)
      for (int j = 0; j < 32; j++)
        if (nums[i] & (1 << j)) cnt[j] = (cnt[j] + 1) % 3;
    int ans = 0;
    for (int i = 0; i < 32; i++)
      if (cnt[i]) ans |= (1 << i);
    return ans;
  }
};