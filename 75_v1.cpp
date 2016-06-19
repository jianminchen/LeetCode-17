/*
  75_v1.cpp
  Sort Colors
*/

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int lo = 0, mid = 0, hi = nums.size();
    while (mid < hi) {
      if (nums[mid] == 0) {
        swap(nums[lo], nums[mid]);
        lo++;
        mid++;
      } else if (nums[mid] == 1)
        mid++;
      else {
        swap(nums[hi - 1], nums[mid]);
        hi--;
      }
    }
  }
};