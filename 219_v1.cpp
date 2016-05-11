/*
  219_v1.cpp
  Contains Duplicate II

  Again I was pretty retarded for my first two WAs.
*/

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
      m[nums[i]] = i;
    }
    return false;
  }
};