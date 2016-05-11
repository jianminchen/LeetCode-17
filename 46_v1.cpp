/*
  46_v1.cpp
  Permutations
*/

class Solution {
  vector<vector<int>> ret;
  void dfs(int curr, int depth, vector<int>& nums, vector<int>& v) {
    if (depth == nums.size()) {
      ret.push_back(v);
    } else {
      for (int i = curr; i < nums.size(); i++) {
        swap(nums[curr], nums[i]);
        v.push_back(nums[curr]);
        dfs(curr + 1, depth + 1, nums, v);
        v.pop_back();
        swap(nums[curr], nums[i]);
      }
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    ret.clear();
    vector<int> curr;
    dfs(0, 0, nums, curr);
    return ret;
  }
};