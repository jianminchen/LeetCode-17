/*
  317_v1.cpp
  Shortest Distance from All Buildings

  My first and second submissions got WA since I didn't notice we need to output
  -1 when it is not possible to find a solution.
*/

class Solution {
 private:
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};
  bool valid(int r, int c, int numRows, int numCols) {
    return 0 <= r && r < numRows && 0 <= c && c < numCols;
  }

 public:
  int shortestDistance(vector<vector<int>>& grid) {
    int numRows = grid.size();
    if (numRows == 0) return 0;
    int numCols = grid[0].size();
    vector<pair<int, int>> buildings;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        if (grid[i][j] == 1) buildings.push_back(make_pair(i, j));
      }
    }
    int dist[numRows][numCols][buildings.size()];
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < buildings.size(); i++) {
      queue<pair<pair<int, int>, int>> q;
      q.push(make_pair(buildings[i], 0));
      dist[buildings[i].first][buildings[i].second][i] = 0;
      while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int r = p.first.first, c = p.first.second, d = p.second;
        // cout << r << " " << c << " " << d << endl;
        for (int j = 0; j < 4; j++) {
          int nr = r + dx[j], nc = c + dy[j];
          if (valid(nr, nc, numRows, numCols) && grid[nr][nc] == 0 &&
              dist[nr][nc][i] == -1) {
            dist[nr][nc][i] = d + 1;
            auto np = make_pair(nr, nc);
            q.push(make_pair(np, d + 1));
          }
        }
      }
    }
    /*
    for (int i = 0; i < buildings.size(); i++) {
        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < numCols; k++) {
                cout << dist[j][k][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    */
    int ans = INT_MAX;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        if (grid[i][j] != 0) continue;
        bool canBuild = true;
        int tmp = 0;
        for (int k = 0; k < buildings.size(); k++) {
          if (dist[i][j][k] == -1) canBuild = false;
          tmp += dist[i][j][k];
        }
        if (canBuild) ans = min(ans, tmp);
      }
    }
    if (ans == INT_MAX) return -1;
    return ans;
  }
};