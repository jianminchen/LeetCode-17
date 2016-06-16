/*
  77_v1.cpp
  Combinations
*/

class Solution {
 private:
  void dfs(int curr, int n, int maxDepth, vector<int>& ans,
           vector<vector<int>>& ret) {
    if (ans.size() == maxDepth) {
      ret.push_back(ans);
      return;
    }
    if (curr > n) return;

    ans.push_back(curr);
    dfs(curr + 1, n, maxDepth, ans, ret);
    ans.pop_back();
    dfs(curr + 1, n, maxDepth, ans, ret);
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> ans;
    vector<vector<int>> ret;
    dfs(1, n, k, ans, ret);
    return ret;
  }
};