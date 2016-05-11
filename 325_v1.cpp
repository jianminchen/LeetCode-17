/*
  325_v1.cpp
  Maximum Size Subarray Sum Equals k
*/

class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = 0;
    int sum = 0, ans = 0;
    for (int i = 1; i <= nums.size(); i++) {
      sum += nums[i - 1];
      if (m.find(sum - k) != m.end()) ans = max(ans, i - m[sum - k]);
      if (m.find(sum) == m.end()) m[sum] = i;
    }
    return ans;
  }
};