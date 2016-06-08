/*
  74_v1.cpp
  Search a 2D Matrix
*/

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if (row == 0) return false;
    int col = matrix[0].size();
    int lo = 0, hi = row * col - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int r = mid / col, c = mid % col;
      if (matrix[r][c] == target)
        return true;
      else if (matrix[r][c] > target)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    return false;
  }
};