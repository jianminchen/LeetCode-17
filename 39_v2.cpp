/*
  39_v2.cpp
  Combination Sum
*/

class Solution {
 private:
  void search(int currIdx, int targetRemain, vector<int>& candidates,
              vector<int>& ans, vector<vector<int>>& ret) {
    if (targetRemain < 0 || currIdx == candidates.size()) return;

    if (targetRemain == 0) {
      ret.push_back(ans);
      return;
    }

    ans.push_back(candidates[currIdx]);
    search(currIdx, targetRemain - candidates[currIdx], candidates, ans, ret);
    ans.pop_back();

    search(currIdx + 1, targetRemain, candidates, ans, ret);
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ret;
    vector<int> ans;
    search(0, target, candidates, ans, ret);
    return ret;
  }
};