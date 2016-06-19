/*
  31_v1.cpp
  Next Permutation

  The algorithm itself is simple: let's take [1 2 3 5 4] as an example, we will
  find the longest non-increasing suffix ([5 4]). Then find the smallest
  number larger than the number preceding this suffix (4) and swap it with
  the number preceding the suffix (3). Now we get something like [1 2 4 5 3] and
  we reverse that non-increasing suffix again so that it becomes a
  non-decreasing suffix [1 2 4 3 5]. This is the next permutation of the
  original one.

  It's a simple algorithm. Instead of swapping the "smallest number larger than
  the number preceding the suffix" with the number preceding the suffix. I was
  instead trying to directly swap the last number with the number preceding the
  suffix, which is completely wrong and doesn't even make sense. So this gave me
  my first WA.

  My second submission contained a subtle bug: for cases like [2, 3, 1, 3, 3],
  we are trying to swap 1 with one of two 3s. The question is which one? We want
  to make the new "reversed suffix" as smaller as possible. Therefore, before
  reversing the suffix, the new suffix after swapping should be "as large as
  possible", which means in the case of a tie we should always try to swap
  the number with the largest index.
*/

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int reverseIdx = nums.size() - 1;
    bool found = false;
    for (int i = reverseIdx - 1; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        reverseIdx = i + 1;
        found = true;
        break;
      }
    }
    if (!found) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int minIdx = -1;
    for (int i = reverseIdx; i < nums.size(); i++) {
      if ((nums[i] > nums[reverseIdx - 1]) &&
          (minIdx == -1 || nums[i] <= nums[minIdx])) {
        minIdx = i;
      }
    }
    swap(nums[reverseIdx - 1], nums[minIdx]);
    reverse(nums.begin() + reverseIdx, nums.end());
  }
};