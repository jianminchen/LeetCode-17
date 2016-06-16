/*
  115_v1.cpp
  Distinct Subsequences
*/

class Solution {
 public:
  int numDistinct(string s, string t) {
    int lenS = s.size(), lenT = t.size();
    if (lenT > lenS || lenS == 0) return 0;
    int f[lenS + 1][lenT + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= lenS; i++) f[i][0] = 1;
    for (int i = 1; i <= lenS; i++) {
      for (int j = 1; j <= min(i, lenT); j++) {
        if (s[i - 1] == t[j - 1])
          f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        else
          f[i][j] = f[i - 1][j];
      }
    }
    return f[lenS][lenT];
  }
};