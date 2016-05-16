/*
  294_v1.cpp
  Flip Game II

  In my first submission I did not use "return true;" but instead set "ret =
  true;". This TLEed...
*/

class Solution {
 public:
  bool canWin(string s) {
    bool ret = false;
    for (int i = 0; i + 1 < s.size(); i++) {
      if (s[i] == '+' && s[i + 1] == '+') {
        s[i] = s[i + 1] = '-';
        if (!canWin(s)) return true;
        s[i] = s[i + 1] = '+';
      }
    }
    return ret;
  }
};