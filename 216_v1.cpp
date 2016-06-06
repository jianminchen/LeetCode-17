/*
  216_v1.cpp
  Combination Sum III
*/

class Solution {
 private:
  vector<vector<int>> ans;

  void search(int depth, int maxDepth, int curr, int remaining, vector<int> v) {
    if (depth == maxDepth) {
      if (remaining == 0) {
        ans.push_back(v);
      }
      return;
    }
    for (int i = curr; i <= min(9, remaining); i++) {
      if (maxDepth == depth + 1 ||
          (remaining - i) / (maxDepth - depth - 1) <= 9) {
        v.push_back(i);
        search(depth + 1, maxDepth, i + 1, remaining - i, v);
        v.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    ans.clear();
    vector<int> v;
    search(0, k, 1, n, v);
    return ans;
  }
};