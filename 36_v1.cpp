/*
    36_v1.cpp
    Valid Sudoku
*/

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    bool used[10];
    for (int i = 0; i < 9; i++) {
      memset(used, false, sizeof(used));
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        int num = board[i][j] - '0';
        if (!used[num])
          used[num] = true;
        else {
          cout << "1" << endl;
          return false;
        }
      }
    }
    for (int i = 0; i < 9; i++) {
      memset(used, false, sizeof(used));
      for (int j = 0; j < 9; j++) {
        if (board[j][i] == '.') continue;
        int num = board[j][i] - '0';
        if (!used[num])
          used[num] = true;
        else {
          cout << "2" << endl;
          return false;
        }
      }
    }
    bool used1[3][3][10];
    memset(used1, false, sizeof(used1));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        if (!used1[i / 3][j / 3][board[i][j] - '0'])
          used1[i / 3][j / 3][board[i][j] - '0'] = true;
        else {
          cout << "3" << endl;
          return false;
        }
      }
    }
    return true;
  }
};