/*
  88_v1.cpp
  Merge Sorted Array

  I didn't quite understand the problem and thought I just need to merge nums1
  and nums2, thus got my first WA. Just remember nums1.size() != m.
*/

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1, p2 = n - 1, p = m + n - 1;
    while (p1 >= 0 && p2 >= 0) {
      if (nums1[p1] < nums2[p2])
        nums1[p] = nums2[p2--];
      else
        nums1[p] = nums1[p1--];
      p--;
    }
    while (p1 >= 0) nums1[p--] = nums1[p1--];
    while (p2 >= 0) nums1[p--] = nums2[p2--];
  }
};