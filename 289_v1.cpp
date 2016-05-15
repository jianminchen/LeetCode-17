/*
  289_v1.cpp
  Game of Life
*/

class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    int numRow = board.size(), numCol = board[0].size();
    vector<vector<int>> boardNext(numRow, vector<int>(numCol));
    for (int i = 0; i < numRow; i++) {
      for (int j = 0; j < numCol; j++) {
        int cnt = 0;
        for (int k = -1; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) continue;
            int nexti = i + k, nextj = j + l;
            if (nexti < 0 || nexti >= numRow || nextj < 0 || nextj >= numCol)
              continue;
            if (board[nexti][nextj] == 1) cnt++;
          }
        }
        if (board[i][j] == 1) {
          if (cnt < 2)
            boardNext[i][j] = 0;
          else if (cnt == 2 || cnt == 3)
            boardNext[i][j] = 1;
          else
            boardNext[i][j] = 0;
        } else {
          if (cnt == 3)
            boardNext[i][j] = 1;
          else
            boardNext[i][j] = 0;
        }
      }
    }
    board = boardNext;
  }
};