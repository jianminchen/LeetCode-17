/*
  221_v1.cpp
  Maximal Square
*/

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int r = matrix.size();
    if (r == 0) return 0;
    int c = matrix[0].size();
    int left[r][c], up[r][c], sq[r][c], ans = 0;
    for (int i = 0; i < r; i++) {
      left[i][0] = (matrix[i][0] == '1');
      for (int j = 1; j < c; j++) {
        if (matrix[i][j] == '0')
          left[i][j] = 0;
        else
          left[i][j] = left[i][j - 1] + 1;
      }
    }
    for (int i = 0; i < c; i++) {
      up[0][i] = (matrix[0][i] == '1');
      for (int j = 1; j < r; j++) {
        if (matrix[j][i] == '0')
          up[j][i] = 0;
        else
          up[j][i] = up[j - 1][i] + 1;
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int val = (i >= 1 && j >= 1 ? sq[i - 1][j - 1] : 0);
        // cout << left[i][j] << " " << up[i][j] << " " << val << endl;
        sq[i][j] = min(min(left[i][j], up[i][j]), val + 1);
        ans = max(sq[i][j], ans);
      }
    }
    return ans * ans;
  }
};