/*
  81_v1.cpp
  Search in Rotated Sorted Array II
*/

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1, mid;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      if (nums[mid] == target) return true;
      if (nums[lo] < nums[mid]) {
        //[lo..mid] sorted
        if (target >= nums[lo] && target <= nums[mid - 1])
          hi = mid - 1;
        else
          lo = mid + 1;
      } else if (nums[lo] > nums[mid]) {
        //[mid + 1..hi] sorted
        if (target >= nums[mid + 1] && target <= nums[hi])
          lo = mid + 1;
        else
          hi = mid - 1;
      } else {
        // nums[lo] == nums[mid] != target
        lo++;
      }
    }
    return false;
  }
};