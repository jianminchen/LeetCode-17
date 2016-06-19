/*
  300_v1.cpp
  Longest Increasing Subsequence
*/

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> f;
    for (int i = 0; i < nums.size(); i++) {
      auto it = lower_bound(f.begin(), f.end(), nums[i]);
      if (it == f.end())
        f.push_back(nums[i]);
      else
        *it = nums[i];
    }
    return f.size();
  }
};