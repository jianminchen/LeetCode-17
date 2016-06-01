/*
  79_v1.cpp
  Word Search

  Again a good idea is to avoid the visited 2D array and use the board array to
  directly store whether a cell has been visited or not.
*/

class Solution {
 private:
  int nRow, nCol;

  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};

  bool valid(int row, int col, vector<vector<bool>>& visited) {
    return 0 <= row && row < nRow && 0 <= col && col < nCol &&
           !visited[row][col];
  }

  bool dfs(int row, int col, string word, int idx,
           vector<vector<bool>>& visited, vector<vector<char>>& board) {
    if (idx == word.size() - 1) return true;
    visited[row][col] = true;
    bool found = false;
    for (int i = 0; i < 4; i++) {
      int nextRow = row + dx[i], nextCol = col + dy[i];
      if (valid(nextRow, nextCol, visited) &&
          word[idx + 1] == board[nextRow][nextCol]) {
        bool flag = dfs(nextRow, nextCol, word, idx + 1, visited, board);
        if (flag) {
          found = true;
          break;
        }
      }
    }
    visited[row][col] = false;
    return found;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    nRow = board.size();
    if (nRow == 0) return false;
    nCol = board[0].size();
    vector<vector<bool>> visited(nRow, vector<bool>(nCol, false));
    for (int i = 0; i < nRow; i++) {
      for (int j = 0; j < nCol; j++) {
        if (board[i][j] == word[0]) {
          bool flag = dfs(i, j, word, 0, visited, board);
          if (flag) return true;
        }
      }
    }
    return false;
  }
};