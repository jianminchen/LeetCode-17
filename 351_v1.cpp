/*
  351_v1.cpp
  Android Unlock Patterns

  Personally I feel this problem is a "reading comprehension problem". Initially
  I thought in each step you can only move to 8 directions but then I've found
  actually the requirement is this "If the line connecting two consecutive keys
  in the pattern passes through any other keys, the other keys must have
  previously selected in the pattern. No jumps through non selected key is
  allowed.".

  This version of the code is based on this discussion:
  https://leetcode.com/discuss/104500/java-solution-with-clear-explanations-and-optimization-81ms

  The use of a 2D skip array in this solution is particularly convenient.
*/

class Solution {
 private:
  int skip[10][10];
  bool visited[10];

  void InitSkipArray() {
    memset(skip, 0, sizeof(skip));
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
    skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] =
        skip[7][3] = skip[4][6] = skip[6][4] = 5;
  }

  int dfs(int currDigit, int remainingDigits) {
    if (remainingDigits == 0) return 1;
    int numPatterns = 0;
    visited[currDigit] = true;
    for (int i = 1; i <= 9; i++) {
      if (!visited[i] &&
          (skip[currDigit][i] == 0 || visited[skip[currDigit][i]]))
        numPatterns += dfs(i, remainingDigits - 1);
    }
    visited[currDigit] = false;
    return numPatterns;
  }

 public:
  int numberOfPatterns(int m, int n) {
    InitSkipArray();
    int numPatterns = 0;
    memset(visited, false, sizeof(visited));
    for (int i = m; i <= n; i++) {
      numPatterns += dfs(1, i - 1) * 4;
      numPatterns += dfs(2, i - 1) * 4;
      numPatterns += dfs(5, i - 1);
    }
    return numPatterns;
  }
};