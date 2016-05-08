/*
    36_v1_im.cpp
    Valid Sudoku
*/

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    bool used1[9][10] = {false}, used2[9][10] = {false}, used3[9][10] = {false};
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '0', idx1 = i, idx2 = j,
              idx3 = i / 3 * 3 + j / 3;
          if (used1[idx1][num] || used2[idx2][num] || used3[idx3][num])
            return false;
          used1[idx1][num] = used2[idx2][num] = used3[idx3][num] = true;
        }
      }
    }
    return true;
  }
};