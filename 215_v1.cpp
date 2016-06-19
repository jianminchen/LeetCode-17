/*
  215_v1.cpp
  Kth Largest Element in an Array

  My first submission got RTE since in the last recursion step I've mistakenly
  written "rank - mid - l".
*/

class Solution {
 private:
  int partition(vector<int>& nums, int l, int r, int rank) {
    if (l == r) return nums[l];

    int randIdx = (rand() % (r - l + 1)) + l;
    swap(nums[l], nums[randIdx]);
    int lo = l, mid = l, hi = r + 1, pivot = nums[l];
    while (mid < hi) {
      if (nums[mid] < pivot) {
        swap(nums[mid], nums[lo]);
        lo++;
        mid++;
      } else if (nums[mid] == pivot)
        mid++;
      else {
        hi--;
        swap(nums[mid], nums[hi]);
      }
    }

    if (rank < lo - l)
      return partition(nums, l, lo - 1, rank);
    else if (rank >= lo - l && rank < mid - l)
      return pivot;
    else
      return partition(nums, hi, r, rank - (mid - l));
  }

 public:
  int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned int)(time(NULL)));
    return partition(nums, 0, nums.size() - 1, nums.size() - k);
  }
};