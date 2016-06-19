/*
  361_v1.cpp
  Bomb Enemy
*/

class Solution {
 public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    int nRow = grid.size();
    if (nRow == 0) return 0;
    int nCol = grid[0].size();
    int left[nRow + 2][nCol + 2], right[nRow + 2][nCol + 2],
        up[nRow + 2][nCol + 2], down[nRow + 2][nCol + 2];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));
    for (int i = 1; i <= nRow; i++) {
      for (int j = 1; j <= nCol; j++) {
        if (grid[i - 1][j - 1] == 'W') {
          left[i][j] = up[i][j] = 0;
        } else if (grid[i - 1][j - 1] == 'E') {
          left[i][j] = left[i][j - 1] + 1;
          up[i][j] = up[i - 1][j] + 1;
        } else {
          left[i][j] = left[i][j - 1];
          up[i][j] = up[i - 1][j];
        }
      }
    }
    for (int i = nRow; i >= 1; i--) {
      for (int j = nCol; j >= 1; j--) {
        if (grid[i - 1][j - 1] == 'W') {
          right[i][j] = down[i][j] = 0;
        } else if (grid[i - 1][j - 1] == 'E') {
          right[i][j] = right[i][j + 1] + 1;
          down[i][j] = down[i + 1][j] + 1;
        } else {
          right[i][j] = right[i][j + 1];
          down[i][j] = down[i + 1][j];
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= nRow; i++) {
      for (int j = 1; j <= nCol; j++) {
        if (grid[i - 1][j - 1] == '0') {
          /*
          cout << i << " " << j << endl;
          cout << left[i][j] << " " << right[i][j] << " " << up[i][j] << " " <<
          down[i][j] << endl;
          */
          ans = max(ans, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
        }
      }
    }
    return ans;
  }
};