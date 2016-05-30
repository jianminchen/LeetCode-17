/*
  351_v2.cpp
  Android Unlock Patterns
*/

int dp[10][1 << 9][10];
int skip[10][10];
bool initialized;

class Solution {
 private:
  void InitSkipArray() {
    memset(skip, 0, sizeof(skip));
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
    skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] =
        skip[8][2] = skip[4][6] = skip[6][4] = 5;
  }

  void calcDP() {
    initialized = true;
    InitSkipArray();
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 9; i++) dp[1][1 << (i - 1)][i] = 1;
    for (int len = 1; len < 9; len++) {
      for (int state = 0; state < (1 << 9); state++) {
        for (int endNode = 1; endNode <= 9; endNode++) {
          if (dp[len][state][endNode]) {
            for (int i = 1; i <= 9; i++) {
              if ((state & (1 << (i - 1))) == 0) {
                int nextState = (state | (1 << (i - 1)));
                if (skip[endNode][i] == 0 ||
                    ((state & (1 << (skip[endNode][i] - 1))) != 0))
                  dp[len + 1][nextState][i] += dp[len][state][endNode];
              }
            }
          }
        }
      }
    }
  }

 public:
  int numberOfPatterns(int m, int n) {
    if (!initialized) {
      calcDP();
    }
    int ans = 0;
    for (int state = 0; state < (1 << 9); state++) {
      for (int len = m; len <= n; len++) {
        for (int endNode = 1; endNode <= 9; endNode++) {
          ans += dp[len][state][endNode];
        }
      }
    }
    return ans;
  }
};