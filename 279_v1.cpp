/*
  279_v1.cpp
  Perfect Squares
*/

class Solution {
 public:
  int numSquares(int n) {
    queue<pair<int, int>> q;
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    for (int i = 1; i * i <= n; i++) {
      q.push(make_pair(i * i, 1));
      visited[i * i] = true;
    }
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int val = p.first;
      int num = p.second;
      if (val == n) return num;
      for (int i = 1; val + i * i <= n; i++) {
        if (!visited[val + i * i]) {
          q.push(make_pair(val + i * i, num + 1));
          visited[val + i * i] = true;
        }
      }
    }
    return -1;
  }
};