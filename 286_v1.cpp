/*
  286_v1.cpp
  Walls and Gates

  My first submission got WA because I didn't consider the speical case where
  "rooms.size() == 0".
*/

class Solution {
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};
  bool valid(int r, int c, int numRows, int numCols) {
    return 0 <= r && r < numRows && 0 <= c && c < numCols;
  }

 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    int numRows = rooms.size();
    if (numRows == 0) return;
    int numCols = rooms[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        if (rooms[i][j] == 0) q.push(make_pair(i, j));
      }
    }
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int r = p.first, c = p.second;
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i], nc = c + dy[i];
        if (valid(nr, nc, numRows, numCols) && rooms[nr][nc] == INT_MAX) {
          q.push(make_pair(nr, nc));
          rooms[nr][nc] = rooms[r][c] + 1;
        }
      }
    }
  }
};