/*
  289_v2.cpp
  Game of Life
*/

class Solution {
  const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

 public:
  void gameOfLife(vector<vector<int>>& board) {
    int numRow = board.size();
    if (numRow == 0) return;
    int numCol = board[0].size();
    vector<int> prevRow(numCol, 0), currRow(numCol, 0);
    for (int i = 0; i < numRow; i++) {
      fill(currRow.begin(), currRow.end(), 0);
      for (int j = 0; j < numCol; j++) {
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
          int neighbori = i + dx[k], neighborj = j + dy[k];
          if (neighbori >= 0 && neighbori < numRow && neighborj >= 0 &&
              neighborj < numCol) {
            if (dx[k] == -1)
              cnt += prevRow[neighborj];
            else
              cnt += board[neighbori][neighborj];
          }
        }
        if (board[i][j] == 1 && cnt >= 2 && cnt <= 3)
          currRow[j] = 1;
        else if (board[i][j] == 0 && cnt == 3)
          currRow[j] = 1;
      }
      prevRow = board[i];
      board[i] = currRow;
    }
  }
};