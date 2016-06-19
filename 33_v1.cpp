/*
  33_v1.cpp
  Search in Rotated Sorted Array
*/

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1, mid, minIdx;
    while (lo < hi) {
      mid = lo + (hi - lo) / 2;
      if (nums[lo] < nums[hi])
        break;
      else if (nums[lo] > nums[mid])
        hi = mid;
      else
        lo = mid + 1;
    }
    minIdx = lo;
    lo = 0;
    hi = nums.size() - 1;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      int newMid = (mid + minIdx) % nums.size();
      if (nums[newMid] == target)
        return newMid;
      else if (nums[newMid] < target)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    return -1;
  }
};