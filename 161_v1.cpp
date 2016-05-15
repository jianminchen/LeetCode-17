/*
  161_v1.cpp
  One Edit Distance

  I've merged the case where diffLen == -1 and diffLen == 1. But my first
  submission only enumerates i from 0 to lenS. This would fail when T = S + one
  character, so I should really enumerate from 0 to max(lenS, lenT).
*/

class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    int lenS = s.size(), lenT = t.size(), diffLen = lenS - lenT;
    if (abs(diffLen) > 1) return false;
    if (diffLen == 0) {
      int cnt = 0;
      for (int i = 0; i < lenS; i++)
        if (s[i] != t[i]) cnt++;
      return cnt == 1;
    } else {
      int sp = 0, tp = 0, cnt = 0;
      for (int i = 0; i < max(lenS, lenT); i++) {
        if (s[sp] == t[tp])
          sp++, tp++;
        else {
          cnt++;
          if (diffLen == 1)
            sp++;
          else
            tp++;
        }
      }
      return cnt == 1;
    }
  }
};