/*
  44_v1.cpp
  Wildcard Matching
*/

class Solution {
 public:
  bool isCharMatch(char s, char p) { return s == p || p == '?'; }
  bool isMatch(string s, string p) {
    int lenS = s.size(), lenP = p.size();
    bool f[lenP + 1] = {0}, g[lenP + 1] = {0};
    f[0] = true;
    for (int i = 1; i <= lenP; i++) f[i] = f[i - 1] && p[i - 1] == '*';
    for (int i = 1; i <= lenS; i++) {
      for (int j = 1; j <= lenP; j++) {
        char sc = s[i - 1], pc = p[j - 1];
        if (pc != '*') {
          if (isCharMatch(sc, pc))
            g[j] = f[j - 1];
          else
            g[j] = false;
        } else {
          g[j] = g[j - 1] || f[j];
        }
      }
      memcpy(f, g, sizeof(g));
    }
    return f[lenP];
  }
};