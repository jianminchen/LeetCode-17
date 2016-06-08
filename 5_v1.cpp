/*
  5_v1.cpp
  Longest Palindromic Substring
*/

class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.size(), ans = 0, bestl, bestr;
    for (int i = 0; i < len; i++) {
      int l = i, r = i;
      while (l >= 0 && r < len && s[l] == s[r]) {
        if (r - l + 1 > ans) {
          ans = r - l + 1;
          bestl = l;
          bestr = r;
        }
        l--;
        r++;
      }
    }
    for (int i = 0; i + 1 < len; i++) {
      int l = i, r = i + 1;
      while (l >= 0 && r < len && s[l] == s[r]) {
        if (r - l + 1 > ans) {
          ans = r - l + 1;
          bestl = l;
          bestr = r;
        }
        l--;
        r++;
      }
    }
    return s.substr(bestl, ans);
  }
};