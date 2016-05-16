/*
  259_v1.cpp
  3Sum Smaller
*/

class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      int p = i + 1, q = nums.size() - 1;
      while (p < q) {
        int sum = nums[i] + nums[p] + nums[q];
        if (sum < target)
          ans += q - p, p++;
        else
          q--;
      }
    }
    return ans;
  }
};