/*
  59_v1.cpp
  Spiral Matrix II
*/

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n, 0));
    int left = 0, right = n - 1, top = 0, bottom = n - 1, curr = 1;
    while (left <= right && top <= bottom) {
      for (int i = left; i <= right; i++) ret[top][i] = curr++;
      top++;
      for (int i = top; i <= bottom; i++) ret[i][right] = curr++;
      right--;
      if (left > right || top > bottom) break;
      for (int i = right; i >= left; i--) ret[bottom][i] = curr++;
      bottom--;
      for (int i = bottom; i >= top; i--) ret[i][left] = curr++;
      left++;
    }
    return ret;
  }
};