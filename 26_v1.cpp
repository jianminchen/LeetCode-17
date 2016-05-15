/*
  26_v1.cpp
  Remove Duplicates from Sorted Array
*/

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int p = 1;
    for (int i = 1; i < nums.size(); i++)
      if (nums[i] != nums[p - 1]) nums[p++] = nums[i];
    return p;
  }
};