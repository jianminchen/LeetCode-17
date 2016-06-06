/*
  15_v1.cpp
  3Sum
*/

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int l = i + 1, r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ret.push_back(vector<int>{nums[i], nums[l], nums[r]});
          l++;
          while (l < r && nums[l] == nums[l - 1]) l++;
        } else if (sum > 0)
          r--;
        else
          l++;
      }
    }
    return ret;
  }
};