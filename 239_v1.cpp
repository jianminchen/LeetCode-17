/*
  239_v1.cpp
  Sliding Window Maximum
*/

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ret;
    if (nums.size() == 0) return ret;
    deque<int> q;
    for (int i = 0; i < nums.size(); i++) {
      while (!q.empty() && i - q.front() >= k) q.pop_front();
      while (!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
      q.push_back(i);
      if (i >= k - 1) ret.push_back(nums[q.front()]);
    }
    return ret;
  }
};