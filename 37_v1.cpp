/*
  37_v1.cpp
  Sudoku Solver

  I forgot to initialize the three used boolean arrays. Therefore my first
  submission got WA.
*/

class Solution {
 private:
  bool used1[9][10], used2[9][10], used3[3][3][10];
  bool dfs(int curr, vector<vector<char>>& board) {
    if (curr == 81) {
      return true;
    }
    int r = curr / 9, c = curr % 9;
    if (board[r][c] != '.') {
      if (dfs(curr + 1, board)) return true;
    } else {
      for (int i = 1; i <= 9; i++) {
        if (!used1[r][i] && !used2[c][i] && !used3[r / 3][c / 3][i]) {
          used1[r][i] = used2[c][i] = used3[r / 3][c / 3][i] = true;
          board[r][c] = i + '0';
          if (dfs(curr + 1, board)) return true;
          used1[r][i] = used2[c][i] = used3[r / 3][c / 3][i] = false;
          board[r][c] = '.';
        }
      }
    }
    return false;
  }

 public:
  void solveSudoku(vector<vector<char>>& board) {
    memset(used1, false, sizeof(used1));
    memset(used2, false, sizeof(used2));
    memset(used3, false, sizeof(used3));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '0';
          used1[i][num] = used2[j][num] = used3[i / 3][j / 3][num] = true;
        }
      }
    }
    dfs(0, board);
  }
};