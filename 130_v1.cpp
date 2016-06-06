/*
  130_v1.cpp
  Surrounded Regions

  My first submission got RTE since I've used DFS and caused stack overflow in a
  large testcase.
*/

class Solution {
 private:
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};

  bool valid(int r, int c, int numRows, int numCols) {
    return 0 <= r && r < numRows && 0 <= c && c < numCols;
  }

 public:
  void solve(vector<vector<char>>& board) {
    int numRows = board.size();
    if (numRows == 0) return;
    int numCols = board[0].size();
    vector<vector<bool>> visited(numRows + 2, vector<bool>(numCols + 2, false));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int r = p.first, c = p.second;
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i], nc = c + dy[i];
        if (valid(nr, nc, numRows + 2, numCols + 2) && !visited[nr][nc] &&
            (nr == 0 || nr == numRows + 1 || nc == 0 || nc == numCols + 1 ||
             board[nr - 1][nc - 1] == 'O')) {
          q.push(make_pair(nr, nc));
          visited[nr][nc] = true;
        }
      }
    }
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        if (board[i][j] == 'O' && !visited[i + 1][j + 1]) board[i][j] = 'X';
      }
    }
  }
};