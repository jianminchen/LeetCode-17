/*
  308_v1.cpp
  Range Sum Query 2D - Mutable
*/

class NumMatrix {
 private:
  vector<vector<int>> matrix;
  vector<vector<int>> bit;
  int nRow, nCol;

  int sum(int r, int c) {
    int ret = 0;
    while (r) {
      int c1 = c;
      while (c1) {
        ret += bit[r][c1];
        c1 -= (c1 & -c1);
      }
      r -= (r & -r);
    }
    return ret;
  }

  void add(int r, int c, int val) {
    while (r <= nRow) {
      int c1 = c;
      while (c1 <= nCol) {
        bit[r][c1] += val;
        c1 += (c1 & -c1);
      }
      r += (r & -r);
    }
  }

 public:
  NumMatrix(vector<vector<int>> &matrix) {
    this->matrix = matrix;
    nRow = matrix.size();
    nCol = (nRow == 0 ? 0 : matrix[0].size());
    bit.resize(nRow + 1);
    for (int i = 0; i <= nRow; i++) {
      bit[i].resize(nCol + 1);
      fill(bit[i].begin(), bit[i].end(), 0);
    }
    for (int i = 1; i <= nRow; i++) {
      for (int j = 1; j <= nCol; j++) {
        add(i, j, matrix[i - 1][j - 1]);
      }
    }
  }

  void update(int row, int col, int val) {
    int diff = val - matrix[row][col];
    add(row + 1, col + 1, diff);
    matrix[row][col] = val;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum(row2 + 1, col2 + 1) - sum(row1, col2 + 1) - sum(row2 + 1, col1) +
           sum(row1, col1);
  }
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);