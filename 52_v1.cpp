/*
  52_v1.cpp
  N-Queens II
*/

class Solution {
 private:
  int ans;
  void solve(int currDepth, int maxDepth, vector<bool>& used1,
             vector<bool>& used2, vector<bool>& used3) {
    if (currDepth == maxDepth) {
      ans++;
      return;
    }
    for (int i = 0; i < maxDepth; i++) {
      if (!used1[i] && !used2[currDepth + i] &&
          !used3[currDepth - i + maxDepth]) {
        used1[i] = used2[currDepth + i] = used3[currDepth - i + maxDepth] =
            true;
        solve(currDepth + 1, maxDepth, used1, used2, used3);
        used1[i] = used2[currDepth + i] = used3[currDepth - i + maxDepth] =
            false;
      }
    }
  }

 public:
  int totalNQueens(int n) {
    if (n == 0) return 0;
    ans = 0;
    vector<bool> used1(n, false);
    vector<bool> used2(2 * n, false);
    vector<bool> used3(2 * n, false);
    solve(0, n, used1, used2, used3);
    return ans;
  }
};