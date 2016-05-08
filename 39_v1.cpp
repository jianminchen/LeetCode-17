/*
  39_v1.cpp
  Combination Sum
*/

class Solution {
 public:
  vector<vector<int>> ans;

  void search(int idx, vector<int>& candidates, vector<int>& v, int target) {
    if (target == 0) {
      ans.push_back(v);
      return;
    } else {
      for (int i = idx; i < candidates.size(); i++) {
        if (target >= candidates[i]) {
          v.push_back(candidates[i]);
          search(i, candidates, v, target - candidates[i]);
          v.pop_back();
        }
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    ans.clear();
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    search(0, candidates, tmp, target);
    return ans;
  }
};