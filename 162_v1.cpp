/*
  162_v1.cpp
  Find Peak Element

  If nums[mid] < nums[mid + 1], then there are two conditions: one is the array
  keeps increasing till nums[n - 1] and then nums[n] = -\inf. So there exists a
  solution; otherwise the array won't keep increasing and at some time there
  might be a "dip", so there exists a solution as well. So no matter what
  happens, if nums[mid] < nums[mid + 1], there exists a solution in [mid + 1,
  hi].

  I've exactly followed the idea on LeetCode discussion page for this problem as
  I could not come up with a solution after 20 minutes. However my first
  submission still got WA since I've written "hi = mid - 1". However, when
  nums[mid] > nums[mid + 1], mid can actually be a valid answer so I should only
  use "hi = mid".
*/

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1, mid;
    while (lo < hi) {
      mid = lo + (hi - lo) / 2;
      if (nums[mid] < nums[mid + 1])
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo;
  }
};