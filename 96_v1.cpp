/*
  96_v1.cpp
  Unique Binary Search Trees
*/

class Solution {
 public:
  int numTrees(int n) {
    int f[n + 1] = {0};
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= i - 1; j++) {
        f[i] += f[j] * f[i - j - 1];
      }
    }
    return f[n];
  }
};