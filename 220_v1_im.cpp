/*
  220_v1_im.cpp
  Contains Duplicate III

  My first submission got WA since I was using ((long long)nums[i] - *it < =t)
  and I forgot to add abs. In fact we don't even need to use abs if we compare
  the difference between *it and nums[i] since *it will be larger than or equal
  to nums[i] - t.
*/

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> s;
    for (int i = 0; i < nums.size(); i++) {
      if (i - k - 1 >= 0) s.erase(nums[i - k - 1]);
      auto it = s.lower_bound(nums[i] - t);
      if (it != s.end() && *it - (long long)nums[i] <= t) return true;
      s.insert(nums[i]);
    }
    return false;
  }
};