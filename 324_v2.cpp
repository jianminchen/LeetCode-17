/*
  324_v2.cpp
  Wiggle Sort II

  Even after I've read the discussion on "virtual indexing", I still could not
  get this submission accepted in my first attempt. The reason is that actually
  my final "wiggle" arrangement was incorrect as well. If I put all the elements
  smaller than median on the odd positions, I would fail on cases like [4, 5, 5,
  6]. For that particular test case I would construct something like [4, 5, 5,
  6]. The correct idea is to start on the even positions and fill in numbers
  that are larger than the median first.

  https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof gives
  a more detailed proof.
*/

class Solution {
 private:
  int partition(vector<int>& nums, int l, int r, int rank) {
    int randIdx = rand() % (r - l + 1) + l;
    swap(nums[randIdx], nums[l]);
    int pivot = nums[l], lo = l, mid = l, hi = r + 1;
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

    if (rank <= lo - l - 1)
      return partition(nums, l, lo - 1, rank);
    else if (rank <= mid - l - 1)
      return pivot;
    else
      return partition(nums, hi, r, rank - (mid - l));
  }

  int map(int idx, int n) {
    return idx < n / 2 ? 2 * idx + 1 : 2 * (idx - n / 2);
  }

 public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return;
    srand((unsigned int)(time(NULL)));
    int median = partition(nums, 0, n - 1, (n - 1) / 2);
    int lo = 0, mid = 0, hi = n;
    while (mid < hi) {
      int map_lo = map(lo, n), map_mid = map(mid, n);
      if (nums[map_mid] > median) {
        swap(nums[map_mid], nums[map_lo]);
        lo++;
        mid++;
      } else if (nums[map_mid] == median)
        mid++;
      else {
        hi--;
        int map_hi = map(hi, n);
        swap(nums[map_mid], nums[map_hi]);
      }
    }
  }
};