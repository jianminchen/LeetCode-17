/*
  254_v1.cpp
  Factor Combinations
*/

class Solution {
  vector<vector<int>> ret;
  void dfs(int curr, vector<int>& v) {
    if (v.size() != 0) {
      v.push_back(curr);
      ret.push_back(v);
      v.pop_back();
    }
    int minVal = 2;
    if (v.size() != 0) minVal = v[v.size() - 1];
    for (int i = minVal; i * i <= curr; i++) {
      if (curr % i == 0) {
        v.push_back(i);
        dfs(curr / i, v);
        v.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> getFactors(int n) {
    ret.clear();
    vector<int> v;
    dfs(n, v);
    return ret;
  }
};