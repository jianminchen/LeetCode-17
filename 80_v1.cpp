/*
  80_v1.cpp
  Remove Duplicates from Sorted Array II
*/

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int p = 0, prev, cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0 || nums[i] != prev) {
        nums[p++] = nums[i];
        prev = nums[i];
        cnt = 1;
      } else {
        if (cnt == 1) {
          nums[p++] = nums[i];
          cnt = 2;
        }
      }
    }
    return p;
  }
};