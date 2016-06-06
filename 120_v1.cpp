/*
  120_v1.cpp
  Triangle
*/

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    if (n == 0) return 0;
    int f[2][n];
    memset(f, 0, sizeof(f));
    f[0][0] = triangle[0][0];
    int flag = 1;
    for (int i = 1; i < n; i++) {
      f[flag][0] = f[1 - flag][0] + triangle[i][0];
      for (int j = 1; j < i; j++)
        f[flag][j] = min(f[1 - flag][j - 1], f[1 - flag][j]) + triangle[i][j];
      f[flag][i] = f[1 - flag][i - 1] + triangle[i][i];
      /*
      for (int j = 0; j <= i; j++)
          cout << f[flag][j] << " ";
      cout << endl;
      */
      flag = 1 - flag;
    }
    int ans = f[1 - flag][0];
    for (int i = 1; i < n; i++) ans = min(ans, f[1 - flag][i]);
    return ans;
  }
};