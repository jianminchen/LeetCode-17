/*
  10_v1.cpp
  Regular Expression Matching

  My first submission got WA because I forgot to initialize the f array as
  false. I don't quite understand why my second submission got WA since I
  believe bool f[lenS + 1][lenP + 1] = {false} should have already initialized
  all values of f.

  Turns out this is incorrect. Basically "int f[100] = {0}" would zero out the
  whole array but "int f[n] = {0}" would not. In fact VS cannot even compile
  this.
*/

class Solution {
  bool isCharMatch(char s, char p) { return s == p || p == '.'; }

 public:
  bool isMatch(string s, string p) {
    int lenS = s.size(), lenP = p.size();
    bool f[lenS + 1][lenP + 1] = {false};
    f[0][0] = true;
    bool flag = true;
    for (int i = 1; i <= lenP; i++) {
      if (p[i - 1] != '*' && (i < lenP && p[i] != '*')) flag = false;
      if (flag && p[i - 1] == '*')
        f[0][i] = true;
      else
        f[0][i] = false;
    }
    for (int i = 1; i <= lenS; i++) {
      for (int j = 1; j <= lenP; j++) {
        char sc = s[i - 1], sp = p[j - 1];
        if (sp != '*') {
          if (isCharMatch(sc, sp))
            f[i][j] = f[i - 1][j - 1];
          else
            f[i][j] = false;
        } else {
          f[i][j] = f[i][j - 2] || (f[i - 1][j] && isCharMatch(sc, p[j - 2]));
        }
      }
    }
    return f[lenS][lenP];
  }
};