/*
  35_v1.cpp
  Search Insert Position
*/

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1, mid, ret = nums.size();
    while (hi >= lo) {
      mid = (lo + hi) >> 1;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target) {
        ret = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    return ret;
  }
};