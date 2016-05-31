/*
  78_v1.cpp
  Subsets
*/

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    for (int i = 0; i < (1 << nums.size()); i++) {
      vector<int> v;
      for (int j = 0; j < nums.size(); j++) {
        if (i & (1 << j)) v.push_back(nums[j]);
      }
      ret.push_back(v);
    }
    return ret;
  }
};