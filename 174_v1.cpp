/*
  174_v1.cpp
  Dungeon Game
*/

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int nRow = dungeon.size(), nCol = nRow ? dungeon[0].size() : 0;
    int dp[nRow + 1][nCol + 1];
    for (int i = 0; i < nCol + 1; i++) dp[nRow][i] = INT_MAX;
    for (int i = 0; i < nRow + 1; i++) dp[i][nCol] = INT_MAX;
    dp[nRow][nCol - 1] = dp[nRow - 1][nCol] = 1;
    for (int i = nRow - 1; i >= 0; i--) {
      for (int j = nCol - 1; j >= 0; j--) {
        int need = min(dp[i][j + 1], dp[i + 1][j]);
        if (dungeon[i][j] >= 0)
          dp[i][j] = max(1, need - dungeon[i][j]);
        else
          dp[i][j] = need - dungeon[i][j];
      }
    }
    return dp[0][0];
  }
};