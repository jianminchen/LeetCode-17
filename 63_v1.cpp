/*
  63_v1.cpp
  Unique Paths II
*/

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int nRows = obstacleGrid.size();
    if (nRows == 0) return 0;
    int nCols = obstacleGrid[0].size();

    int f[nRows][nCols];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < nRows; i++) {
      if (obstacleGrid[i][0] == 1) break;
      f[i][0] = 1;
    }
    for (int i = 0; i < nCols; i++) {
      if (obstacleGrid[0][i] == 1) break;
      f[0][i] = 1;
    }
    for (int i = 1; i < nRows; i++) {
      for (int j = 1; j < nCols; j++) {
        if (obstacleGrid[i][j] == 1)
          f[i][j] = 0;
        else
          f[i][j] = f[i - 1][j] + f[i][j - 1];
      }
    }
    return f[nRows - 1][nCols - 1];
  }
};