/*
  240_v1.cpp
  Search a 2D Matrix II
*/

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if (row == 0) return false;
    int col = matrix[0].size();
    int r = 0, c = col - 1;
    while (r >= 0 && r < row && c >= 0 && c < col) {
      if (matrix[r][c] == target)
        return true;
      else if (target < matrix[r][c])
        c--;
      else
        r++;
    }
    return false;
  }
};