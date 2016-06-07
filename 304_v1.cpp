/*
  304_v1.cpp
  Range Sum Query 2D - Immutable

  My first submission got WA since I didn't handle the case where matrix is
  empty.
*/

class NumMatrix {
 private:
  vector<vector<int>> sum;

 public:
  NumMatrix(vector<vector<int>> &matrix) {
    int numRows = matrix.size(), numCols;
    if (numRows == 0)
      numCols = 0;
    else
      numCols = matrix[0].size();
    sum = vector<vector<int>>(numRows + 1, vector<int>(numCols + 1, 0));
    for (int i = 1; i <= numRows; i++) {
      for (int j = 1; j <= numCols; j++)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                    matrix[i - 1][j - 1];
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int a = sum[row1][col1];
    int b = sum[row2 + 1][col1];
    int c = sum[row1][col2 + 1];
    int d = sum[row2 + 1][col2 + 1];
    return d - b - c + a;
  }
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);