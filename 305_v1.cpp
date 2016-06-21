/*
  305_v1.cpp
  Number of Islands II
*/

class Solution {
 private:
  vector<int> parent, rank;

  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};

  bool valid(int r, int c, int m, int n) {
    return 0 <= r && r < m && 0 <= c && c < n;
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    else
      return parent[x] = find(parent[x]);
  }

  bool unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return false;
    if (rank[rx] < rank[ry])
      parent[rx] = ry;
    else {
      parent[ry] = rx;
      if (rank[rx] == rank[ry]) rank[rx]++;
    }
    return true;
  }

 public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    parent.resize(m * n);
    rank.resize(m * n);
    for (int i = 0; i < m * n; i++) {
      parent[i] = -1;
      rank[i] = 0;
    }
    int numIslands = 0;
    vector<int> ret;
    for (int i = 0; i < positions.size(); i++) {
      int r = positions[i].first, c = positions[i].second;
      int idx = r * n + c;
      parent[idx] = idx;
      numIslands++;
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i], nc = c + dy[i], nIdx = nr * n + nc;
        if (valid(nr, nc, m, n) && parent[nIdx] != -1) {
          if (unite(idx, nIdx)) numIslands--;
        }
      }
      ret.push_back(numIslands);
    }
    return ret;
  }
};