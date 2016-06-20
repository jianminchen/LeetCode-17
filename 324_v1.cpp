/*
  324_v1.cpp
  Wiggle Sort II

  We can find the median in O(n) time by using the quickselect algorithm. Then
  we can just get the desired output by putting all nums[0..mid] on the even
  indices and the rest on the odd indices. My issue here is I don't know how we
  can achieve this swap in-place.
*/

class Solution {
 private:
  int partition(vector<int>& nums, int l, int r, int rank) {
    // rank is between [0, r - l].
    if (l == r) return nums[l];

    int randIdx = rand() % (r - l + 1) + l;
    swap(nums[l], nums[randIdx]);
    int pivot = nums[l], lo = l, mid = l, hi = r + 1;
    while (mid < hi) {
      if (nums[mid] < pivot) {
        swap(nums[lo], nums[mid]);
        lo++;
        mid++;
      } else if (nums[mid] == pivot) {
        mid++;
      } else {
        hi--;
        swap(nums[mid], nums[hi]);
      }
    }
    if (rank <= lo - l - 1)
      return partition(nums, l, lo - 1, rank);
    else if (rank > lo - l - 1 && rank <= mid - l - 1)
      return pivot;
    else
      return partition(nums, hi, r, rank - (mid - l));
  }

 public:
  void wiggleSort(vector<int>& nums) {
    srand((unsigned int)(time(NULL)));
    int n = nums.size();
    if (n == 0) return;
    int median = partition(nums, 0, n - 1, (n - 1) / 2);
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
    cout << median << endl;
    int lo = (n - 1) / 2 + 1, hi = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 1)
        swap(nums[i], nums[lo++]);
      else
        swap(nums[i], nums[hi++]);
    }
  }
};