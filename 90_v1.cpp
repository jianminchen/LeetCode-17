/*
  90_v1.cpp
  Subsets II
*/

class Solution {
 private:
  void dfs(int curr, vector<int>& nums, vector<int>& ans,
           vector<vector<int>>& ret) {
    if (curr == nums.size()) {
      ret.push_back(ans);
      return;
    }
    int nextPos;
    for (nextPos = curr + 1; nextPos < nums.size(); nextPos++)
      if (nums[nextPos] != nums[curr]) break;
    dfs(nextPos, nums, ans, ret);

    ans.push_back(nums[curr]);
    dfs(curr + 1, nums, ans, ret);
    ans.pop_back();
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    vector<int> ans;
    dfs(0, nums, ans, ret);
    return ret;
  }
};