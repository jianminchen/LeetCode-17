/*
  349_v1.cpp
  Intersection of Two Arrays

  My first submission got WA since I didn't notice the requirement of uniqueness
  in the result vector.
*/

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    if (nums1.size() == 0 || nums2.size() == 0) return ret;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int p1 = 0, p2 = 0, prev;
    bool first = true;
    while (p1 < nums1.size() && p2 < nums2.size()) {
      if (nums1[p1] == nums2[p2]) {
        if (first || nums1[p1] != prev) {
          prev = nums1[p1];
          first = false;
          ret.push_back(nums1[p1]);
        }
        p1++;
        p2++;
      } else if (nums1[p1] < nums2[p2])
        p1++;
      else
        p2++;
    }
    return ret;
  }
};