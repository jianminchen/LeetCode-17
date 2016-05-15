/*
  151_v2.cpp
  Reverse Wors in a String

  I've initially written s[p++] = s[j] so my first submission got WA. This
  version is based on LC discussion and is really elegant.
*/

class Solution {
 public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        if (p != 0) s[p++] = ' ';
        int j = i;
        while (j < s.size() && s[j] != ' ') s[p++] = s[j++];
        reverse(s.begin() + p - (j - i), s.begin() + p);
        i = j;
      }
    }
    s.erase(s.begin() + p, s.end());
  }
};