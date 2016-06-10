/*
  91_v1.cpp
  Decode Ways

  My first two submissions got WA because I didn't consider the '0' case
  carefully.
*/

class Solution {
 public:
  int numDecodings(string s) {
    int len = s.size();
    if (len == 0) return 0;
    int f[len + 1];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1; i <= len; i++) {
      if (s[i - 1] != '0') f[i] = f[i - 1];
      if (i >= 2) {
        int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (val >= 10 && val <= 26) f[i] += f[i - 2];
      }
    }
    return f[len];
  }
};