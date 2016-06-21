/*
  32_v1.cpp
  Longest Valid Parentheses

  A simple DP problem.

  My first submission got WA because of this bug: when s[i - 1] is ')', we need
  to check whether prevIdx is '(', if it is '(' then it means we have another
  matching pair. However, when this happens we should not just assign f[i] = f[i
  - 1] + 2. We should also add f[prevIdx - 1] since now [prevIdx .. i] as a
  whole is a balanced sequence that can be extended on both sides.

  My second submission got WA since when checking whether s[prevIdx] == '(' I
  didn't add the condition that prevIdx must be >= 0.
*/

class Solution {
 public:
  int longestValidParentheses(string s) {
    int n = s.size(), f[n];
    memset(f, 0, sizeof(f));
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == '(') continue;
      if (s[i - 1] == '(') {
        if (i >= 2)
          f[i] = f[i - 2] + 2;
        else
          f[i] = 2;
      } else {  // s[i - 1] == ')'
        int prevIdx = i - 1 - f[i - 1];
        if (prevIdx >= 0 && s[prevIdx] == '(') {
          f[i] = f[i - 1] + 2;
          if (prevIdx >= 1) f[i] += f[prevIdx - 1];
        }
      }
      ans = max(ans, f[i]);
    }
    return ans;
  }
};