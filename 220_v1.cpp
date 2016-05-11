/*
  220_v1.cpp
  Contains Duplicate III

  I've mistakenly added "s.insert(nums[i])" inside the "if (!s.empty())" block
  so I got my first WA. I got my second WA since I didn't notice (nums[i] - *it)
  could possibly overflow.
*/

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> s;
    for (int i = 0; i < nums.size(); i++) {
      if (i - k - 1 >= 0) s.erase(nums[i - k - 1]);
      if (!s.empty()) {
        auto it = s.lower_bound(nums[i]);
        if (it != s.end()) {
          if (abs((long long)nums[i] - *it) <= t) return true;
        }
        if (it != s.begin()) {
          it--;
          if (abs((long long)nums[i] - *it) <= t) return true;
        }
      }
      s.insert(nums[i]);
    }
    return false;
  }
};