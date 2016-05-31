/*
  296_v1.cpp
  Best Meeting Point

  My first submission got WA because I've mistakenly thought grid is a N * 2
  array and then used grid.size() as an indicator of the number of valid 2D
  coordinates.
*/

class Solution {
 public:
  int minTotalDistance(vector<vector<int>>& grid) {
    vector<int> x, y;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          x.push_back(i);
          y.push_back(j);
        }
      }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int medianX, medianY;
    if (x.size() % 2 == 0)
      medianX = (x[x.size() / 2] + x[x.size() / 2 - 1]) / 2;
    else
      medianX = x[x.size() / 2];
    if (y.size() % 2 == 0)
      medianY = (y[y.size() / 2] + y[y.size() / 2 - 1]) / 2;
    else
      medianY = y[y.size() / 2];

    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          ans += abs(medianX - i) + abs(medianY - j);
        }
      }
    }
    return ans;
  }
};