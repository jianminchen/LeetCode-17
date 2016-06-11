/*
  209_v1.cpp
  Minimum Size Subarray Sum
*/

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int l = 0, r = 0, n = nums.size(), sum = nums[r];
    int minLen = INT_MAX;
    while (l < n && r < n) {
      if (sum < s) {
        r++;
        if (r < n) sum += nums[r];
      } else {
        minLen = min(minLen, r - l + 1);
        l++;
        sum -= nums[l - 1];
      }
    }
    if (minLen == INT_MAX) return 0;
    return minLen;
  }
};