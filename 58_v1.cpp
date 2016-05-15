/*
  58_v1.cpp
  Length of Last Word
*/

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int cnt = 0, ret = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        if (cnt != 0) ret = cnt;
        cnt = 0;
      } else
        cnt++;
    }
    if (cnt != 0) ret = cnt;
    return ret;
  }
};