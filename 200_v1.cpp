/*
  200_v1.cpp
  Number of Islands
*/

class Solution {
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};
  void dfs(int row, int col, vector<vector<char>>& grid,
           vector<vector<bool>>& visited) {
    visited[row][col] = true;
    for (int i = 0; i < 4; i++) {
      int nextRow = row + dx[i];
      int nextCol = col + dy[i];
      if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 &&
          nextCol < grid[0].size() && !visited[nextRow][nextCol] &&
          grid[nextRow][nextCol] == '1')
        dfs(nextRow, nextCol, grid, visited);
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int numRows = grid.size();
    if (numRows == 0) return 0;
    int numCols = grid[0].size();
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
    int numIslands = 0;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          dfs(i, j, grid, visited);
          numIslands++;
        }
      }
    }
    return numIslands;
  }
};