/*
  287_v1.cpp
  Find the Duplicate Number

  The basic idea is to use the pigeonhole principle to count how many numbers
  are in [lo, mid - 1] for the input array. Then we can apply the idea of binary
  search.

  My first submission got WA since when I'm counting cnt, I only considered
  nums[i] < mid but I forgot I should actually add nums[i] >= lo as well.
*/

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
    int lo = 1, hi = n, mid;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      int cnt = 0, cnt_mid = 0;
      for (int i = 0; i < n + 1; i++) {
        if (nums[i] < mid && nums[i] >= lo)
          cnt++;
        else if (nums[i] == mid)
          cnt_mid++;
      }
      /*
      printf("lo = %d, hi = %d, mid = %d\n", lo, hi, mid);
      printf("cnt = %d, cnt_mid = %d\n", cnt, cnt_mid);
      */
      if (cnt_mid > 1) return mid;

      if (cnt <= mid - lo)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    return -1;
  }
};