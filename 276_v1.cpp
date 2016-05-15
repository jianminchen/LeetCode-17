/*
  276_v1.cpp
  Paint Fence
*/

class Solution {
 public:
  int numWays(int n, int k) {
    if (n == 0) return 0;
    int f[n + 1][2];
    memset(f, 0, sizeof(f));
    f[1][0] = k;
    f[1][1] = 0;
    f[2][0] = k * (k - 1);
    f[2][1] = k;
    for (int i = 3; i <= n; i++) {
      f[i][0] = f[i - 1][0] * (k - 1) + f[i - 1][1] * (k - 1);
      f[i][1] = f[i - 1][0];
    }
    return f[n][0] + f[n][1];
  }
};