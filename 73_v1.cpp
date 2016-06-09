/*
  73_v1.cpp
  Set Matrix Zeroes

  Honestly I don't know what I was thinking for my first version. Why do I set
  matrix[0][i] as 1 after checking them? What was my concern at that time?
*/

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (row == 0) return;
    int col = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    for (int i = 0; i < col; i++) {
      if (matrix[0][i] == 0) {
        firstRowZero = true;
      }
    }

    for (int i = 0; i < row; i++) {
      if (matrix[i][0] == 0) {
        firstColZero = true;
      }
    }

    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < row; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < col; j++) matrix[i][j] = 0;
      }
    }

    for (int i = 1; i < col; i++) {
      if (matrix[0][i] == 0) {
        for (int j = 0; j < row; j++) matrix[j][i] = 0;
      }
    }

    if (firstRowZero) {
      for (int i = 0; i < col; i++) matrix[0][i] = 0;
    }

    if (firstColZero) {
      for (int i = 0; i < row; i++) matrix[i][0] = 0;
    }
  }
};