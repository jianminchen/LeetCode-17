/*
  34_v1.cpp
  Search for a Range
*/

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int lo = 0, hi = n - 1, mid, idx1 = -1, idx2 = -1;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      if (nums[mid] > target)
        hi = mid - 1;
      else if (nums[mid] < target)
        lo = mid + 1;
      else {
        hi = mid - 1;
        idx1 = mid;
      }
    }
    lo = 0, hi = n - 1;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      if (nums[mid] > target)
        hi = mid - 1;
      else if (nums[mid] < target)
        lo = mid + 1;
      else {
        lo = mid + 1;
        idx2 = mid;
      }
    }
    return vector<int>{idx1, idx2};
  }
};