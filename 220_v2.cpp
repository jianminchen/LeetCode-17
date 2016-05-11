/*
  220_v2.cpp
  Contains Duplicate III

  This solution is based on distributing nums into buckets. One minor issue
  we need to take care of is when nums[i] < 0. For instance, when nums[i] = -3
  and t = 4 we would hope -3 gets put into the bucket -1 but if we just use
  nums[i] / (t + 1) it would be put to bucket 0. Therefore I'm using floor(x) to
  fix this problem. LC discussion repositions all nums by performing nums[i] -=
  INT_MIN;

  My first submission got RTE since t can be -1. My second submission got WA
  because I directly used nums[i] / (t + 1). My third submission got WA because
  I forgot to use long long where needed.
*/

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (t < 0) return false;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (i - k - 1 >= 0)
        m.erase(floor(1.0 * nums[i - k - 1] / ((long long)t + 1)));
      int bucket = floor(1.0 * nums[i] / ((long long)t + 1));
      if (m.find(bucket) != m.end() ||
          (m.find(bucket - 1) != m.end() &&
           (long long)nums[i] - m[bucket - 1] <= t) ||
          (m.find(bucket + 1) != m.end() &&
           (long long)m[bucket + 1] - nums[i] <= t))
        return true;
      m.insert(make_pair(bucket, nums[i]));
    }
    return false;
  }
};