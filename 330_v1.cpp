/*
  330_v1.cpp
  Patching Array

  I've created an array of size n + 1 in my first submission but turns out I
  haven't used it at all. Thus apparently my first submission received an RTE...
*/

class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    long long miss = 1;
    int ans = 0, curr = 0;
    while (miss <= n) {
      if (curr < nums.size() && nums[curr] <= miss)
        miss += nums[curr++];
      else {
        ans++;
        miss *= 2;
      }
    }
    return ans;
  }
};