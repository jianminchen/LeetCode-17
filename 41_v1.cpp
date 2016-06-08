/*
  41_v1.cpp
  First Missing Positive

  My first submission didn't consider the case where nums[targetIdx] ==
  targetIdx + 1. One example of such a case is [1, 1] so we will get stuck in
  the loop. In fact I'm making the check a bit complicated than necessary, we
  can safely remove the "targetIdx != i" part, because this basically indicates
  whether the current number A[i] is already at its target position - instead of
  checking this, we can check whether the target position already contains A[i].
  Notice the slight difference between the two conditions, the second condition
  will always terminate because after you swap the number, the target position
  would then contain A[i].
*/

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int targetIdx = nums[i] - 1;
      while (targetIdx >= 0 && targetIdx <= n - 1 && targetIdx != i &&
             nums[targetIdx] != targetIdx + 1) {
        swap(nums[i], nums[targetIdx]);
        targetIdx = nums[i] - 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) return i + 1;
    }
    return n + 1;
  }
};