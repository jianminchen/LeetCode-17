/*
  363_v1.cpp
  Max Sum of Rectangle No Larger Than K

  My first submission got WA because of a rookie mistake. My for-loop variable k
  has actually hidden the input argument k. :p
*/

class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int row = matrix.size(), col = row ? matrix[0].size() : 0;
    vector<vector<int>> m;
    if (row <= col)
      m = matrix;
    else {
      // row > col;
      m.resize(col);
      for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++) m[i].push_back(matrix[j][i]);
    }
    row = m.size(), col = row ? m[0].size() : 0;
    vector<vector<int>> partialSum(row + 1, vector<int>(col, 0));
    for (int i = 1; i <= row; i++) {
      for (int j = 0; j < col; j++)
        partialSum[i][j] = partialSum[i - 1][j] + m[i - 1][j];
    }

    int maxAns = 0, sumThreshold = k;
    bool foundAns = false;
    for (int i = 0; i <= row; i++) {
      for (int j = i + 1; j <= row; j++) {
        set<int> s;
        s.insert(0);
        int prev = 0;
        for (int k = 0; k < col; k++) {
          int next = prev + partialSum[j][k] - partialSum[i][k];
          auto it = s.lower_bound(next - sumThreshold);
          if (it != s.end()) {
            int tmpAns = next - (*it);
            // printf("*(it) = %d, tmpAns = %d\n", (*it), tmpAns);
            if (!foundAns || tmpAns > maxAns) {
              foundAns = true;
              maxAns = tmpAns;
            }
          }
          s.insert(next);
          prev = next;
        }
        // printf("\n");
      }
    }
    return maxAns;
  }
};