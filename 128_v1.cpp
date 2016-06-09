/*
  128_v1.cpp
  Longest Consecutive Sequence

  My first submission failed in the case where largerFound and smallerFound both
  equal to true (i.e. we need to update the length of the consecutive sequence
  on both boundaries). However, I forgot to set m[nums[i]] in this case so
  nums[i] will still be marked as not seen and thus this breaks the code.
*/

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> m;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(nums[i]) != m.end()) continue;
      bool smallerFound = (m.find(nums[i] - 1) != m.end());
      bool largerFound = (m.find(nums[i] + 1) != m.end());
      if (smallerFound == false && largerFound == false) {
        m[nums[i]] = 1;
        ans = max(ans, 1);
      } else if (smallerFound && !largerFound) {
        int leftBoundary = nums[i] - m[nums[i] - 1];
        m[leftBoundary]++;
        m[nums[i]] = m[leftBoundary];
        ans = max(ans, m[leftBoundary]);
      } else if (largerFound && !smallerFound) {
        int rightBoundary = nums[i] + m[nums[i] + 1];
        m[rightBoundary]++;
        m[nums[i]] = m[rightBoundary];
        ans = max(ans, m[rightBoundary]);
      } else {
        int leftBoundary = nums[i] - m[nums[i] - 1];
        int rightBoundary = nums[i] + m[nums[i] + 1];
        int newLen = m[nums[i] - 1] + m[nums[i] + 1] + 1;
        m[leftBoundary] = m[rightBoundary] = m[nums[i]] = newLen;
        ans = max(ans, newLen);
      }
      // cout << nums[i] << " " << ans << endl;
    }
    return ans;
  }
};