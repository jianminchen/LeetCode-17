/*
  132_v1.cpp
  Palindrome Partitioning II
*/

class Solution {
 public:
  int minCut(string s) {
    int len = s.size();
    if (len == 0) return 0;
    bool isPalindrome[len][len];
    memset(isPalindrome, false, sizeof(isPalindrome));
    for (int i = 0; i < len; i++) isPalindrome[i][i] = true;
    for (int i = 0; i + 1 < len; i++)
      if (s[i] == s[i + 1]) isPalindrome[i][i + 1] = true;
    for (int l = 2; l < len; l++) {
      for (int i = 0; i + l < len; i++)
        if (s[i] == s[i + l] && isPalindrome[i + 1][i + l - 1])
          isPalindrome[i][i + l] = true;
    }
    int f[len + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= len; i++) {
      for (int j = 0; j < i; j++) {
        if (isPalindrome[j][i - 1]) {
          if (f[i] == 0 || f[i] > f[j] + 1) f[i] = f[j] + 1;
        }
      }
    }
    return f[len] - 1;
  }
};