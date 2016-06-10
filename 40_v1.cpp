/*
  40_v1.cpp
  Combination Sum II
*/

class Solution {
 private:
  void dfs(int currIdx, vector<int>& candidates, int remaining,
           vector<int>& curr, vector<vector<int>>& ret) {
    if (remaining == 0) {
      ret.push_back(curr);
      return;
    }
    if (currIdx == candidates.size()) return;
    int nextIdx;
    for (nextIdx = currIdx + 1; nextIdx < candidates.size(); nextIdx++)
      if (candidates[nextIdx] != candidates[currIdx]) break;
    dfs(nextIdx, candidates, remaining, curr, ret);
    if (remaining >= candidates[currIdx]) {
      curr.push_back(candidates[currIdx]);
      dfs(currIdx + 1, candidates, remaining - candidates[currIdx], curr, ret);
      curr.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    sort(candidates.begin(), candidates.end());
    if (candidates.size() == 0) return ret;
    vector<int> curr;
    dfs(0, candidates, target, curr, ret);
    return ret;
  }
};