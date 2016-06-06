/*
  51_v1.cpp
  N-Queens
*/

class Solution {
  void solve(int currDepth, int maxDepth, vector<int>& v,
             vector<vector<string>>& ans, vector<bool>& used1,
             vector<bool>& used2, vector<bool>& used3) {
    if (currDepth == maxDepth) {
      vector<string> vs;
      for (int i = 0; i < maxDepth; i++) {
        string str(maxDepth, '.');
        vs.push_back(str);
      }
      for (int i = 0; i < maxDepth; i++) vs[i][v[i]] = 'Q';
      ans.push_back(vs);
      return;
    }
    for (int i = 0; i < maxDepth; i++) {
      int val1 = i;
      int val2 = currDepth + i;
      int val3 = currDepth - i + maxDepth;
      if (!used1[val1] && !used2[val2] && !used3[val3]) {
        used1[val1] = used2[val2] = used3[val3] = true;
        v.push_back(i);
        solve(currDepth + 1, maxDepth, v, ans, used1, used2, used3);
        used1[val1] = used2[val2] = used3[val3] = false;
        v.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> v;
    vector<bool> used1(n, false);
    vector<bool> used2(2 * n, false);
    vector<bool> used3(2 * n, false);
    solve(0, n, v, ans, used1, used2, used3);
    cout << ans.size() << endl;
    return ans;
  }
};