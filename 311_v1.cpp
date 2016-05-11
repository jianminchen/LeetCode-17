/*
  311_v1.cpp
  Sparse Matrix Multiplication
*/

class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int a = A.size(), b = B.size(), c = B[0].size();
    vector<vector<int>> ret(a, vector<int>(c));
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (A[i][j]) {
          for (int k = 0; k < c; k++) ret[i][k] += A[i][j] * B[j][k];
        }
      }
    }
    return ret;
  }
};