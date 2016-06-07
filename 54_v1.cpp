/*
  54_v1.cpp
  Spiral Matrix
*/

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ret;
    int numRows = matrix.size();
    if (numRows == 0) return ret;
    int numCols = matrix[0].size();
    int left = 0, right = numCols - 1, top = 0, bottom = numRows - 1;
    while (true) {
      for (int i = left; i <= right; i++) ret.push_back(matrix[top][i]);
      if (ret.size() == numRows * numCols) break;
      top++;
      for (int i = top; i <= bottom; i++) ret.push_back(matrix[i][right]);
      if (ret.size() == numRows * numCols) break;
      right--;
      for (int i = right; i >= left; i--) ret.push_back(matrix[bottom][i]);
      if (ret.size() == numRows * numCols) break;
      bottom--;
      for (int i = bottom; i >= top; i--) ret.push_back(matrix[i][left]);
      if (ret.size() == numRows * numCols) break;
      left++;
    }
    return ret;
  }
};