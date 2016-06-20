/*
  312_v1.cpp
  Burst Balloons
*/

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < nums.size(); i++) v.push_back(nums[i]);
    v.push_back(1);
    int n = v.size(), f[n][n];
    memset(f, 0, sizeof(f));
    for (int i = 0; i + 2 < n; i++) f[i][i + 2] = v[i] * v[i + 1] * v[i + 2];
    for (int len = 3; len <= n - 1; len++) {
      for (int i = 0; i + len < n; i++) {
        int tmp = 0;
        for (int j = i + 1; j < i + len; j++)
          tmp = max(tmp, f[i][j] + f[j][i + len] + v[i] * v[j] * v[i + len]);
        f[i][i + len] = tmp;
      }
    }
    return f[0][n - 1];
  }
};