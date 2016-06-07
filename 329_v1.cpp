/*
  329_v1.cpp
  Longest Increasing Path in a Matrix
*/

class Solution {
 private:
  vector<vector<int>> dp;
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};
  bool valid(int r, int c, int numRows, int numCols) {
    return 0 <= r && r < numRows && 0 <= c && c < numCols;
  }
  int solve(int r, int c, int numRows, int numCols,
            vector<vector<int>>& matrix) {
    if (dp[r][c] != -1) return dp[r][c];
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      int nr = r + dx[i], nc = c + dy[i];
      if (valid(nr, nc, numRows, numCols) && matrix[nr][nc] > matrix[r][c])
        ans = max(ans, solve(nr, nc, numRows, numCols, matrix));
    }
    return dp[r][c] = ans + 1;
  }

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int numRows = matrix.size(), numCols;
    if (numRows == 0) return 0;
    numCols = matrix[0].size();
    dp = vector<vector<int>>(numRows, vector<int>(numCols, -1));
    int ans = 0;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        ans = max(ans, solve(i, j, numRows, numCols, matrix));
      }
    }
    return ans;
  }
};