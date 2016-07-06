/*
  75_v2.cpp
  Sort Colors
*/

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    //[0, lo) -> 0
    //[lo, mid) -> 1
    //[mid, hi) -> unknown
    //[hi, nums.size() - 1] -> 2
    int lo = 0, mid = 0, hi = nums.size();
    while (mid < hi) {
      if (nums[mid] == 0) {
        swap(nums[mid], nums[lo]);
        lo++;
        mid++;
      } else if (nums[mid] == 1) {
        mid++;
      } else {
        hi--;
        swap(nums[mid], nums[hi]);
      }
    }
  }
};