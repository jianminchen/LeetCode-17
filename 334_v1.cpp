/*
  334_v1.cpp
  Increasing Triplet Subsequence
*/

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;
    int minOne = nums[0], minTwo, len = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (len == 1) {
        if (nums[i] > minOne) {
          minTwo = nums[i];
          len = 2;
        } else if (nums[i] < minOne)
          minOne = nums[i];
      } else if (len == 2) {
        if (nums[i] > minTwo)
          return true;
        else if (nums[i] < minTwo && nums[i] > minOne)
          minTwo = nums[i];
        else if (nums[i] < minOne)
          minOne = nums[i];
      }
    }
    return false;
  }
};