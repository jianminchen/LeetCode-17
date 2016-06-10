/*
  97_v1.cpp
  Interleaving String

  My first submission cannot even past the sample test case...anyway, I got a WA
  from my first submission...
*/

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
    if (l3 != l2 + l1) return false;
    if (l1 == 0) return s3 == s2;
    if (l2 == 0) return s3 == s1;
    if (l3 == 0) return false;

    bool f[l1 + 1][l2 + 1];
    memset(f, false, sizeof(f));
    f[0][0] = true;
    for (int i = 0; i <= l1; i++) {
      for (int j = 0; j <= l2; j++) {
        if (i > 0 && s1[i - 1] == s3[i + j - 1]) f[i][j] |= f[i - 1][j];
        if (j > 0 && s2[j - 1] == s3[i + j - 1]) f[i][j] |= f[i][j - 1];
      }
    }
    return f[l1][l2];
  }
};