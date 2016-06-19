/*
  153_v1.cpp
  Find Minimum in Rotated Sorted Array
*/

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1, mid;
    while (lo < hi) {
      mid = lo + (hi - lo) / 2;
      if (nums[lo] < nums[hi])
        return nums[lo];
      else if (nums[lo] > nums[mid])
        hi = mid;
      else
        lo = mid + 1;
    }
    return nums[lo];
  }
};