/*
  47_v1.cpp
  Permutations II
*/

class Solution {
 private:
  void dfs(int curr, vector<int> nums, vector<vector<int>>& ret) {
    if (curr == nums.size()) {
      ret.push_back(nums);
      return;
    }
    for (int i = curr; i < nums.size(); i++) {
      if (i == curr || nums[i] != nums[curr]) {
        swap(nums[curr], nums[i]);
        dfs(curr + 1, nums, ret);
      }
    }
  }

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    dfs(0, nums, ret);
    cout << ret.size() << endl;
    return ret;
  }
};