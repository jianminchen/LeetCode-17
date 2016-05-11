/*
  283_v1.cpp
  Move Zeroes

  I've put p++ in the "if (i != p)" block and got my first WA.
*/

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int p = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        if (i != p) swap(nums[i], nums[p]);
        p++;
      }
    }
  }
};