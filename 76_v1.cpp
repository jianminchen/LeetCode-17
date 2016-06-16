/*
  76_v1.cpp
  Minimum Window Substring

  My first submission received WA because I thought we need to de-duplicate the
  characters appeared in T. My second submission got WA since I was returning
  something completely stupid. What's s.substr(l, r - l + 1)?
*/

class Solution {
 public:
  string minWindow(string s, string t) {
    int cnt[256] = {0}, cntT[256] = {0};
    int numCh = 0, numTarget = 0;
    for (char ch : t) cntT[ch]++;
    for (int i = 0; i < 256; i++) {
      if (cntT[i]) numTarget++;
    }

    int l = 0, r = 0, ans = INT_MAX, bestl = 0;
    while (l < s.size() && r < s.size()) {
      cnt[s[r]]++;
      if (cntT[s[r]] != 0 && cnt[s[r]] == cntT[s[r]]) numCh++;
      if (numCh == numTarget) {
        while (l < r && (cnt[s[l]] > cntT[s[l]])) {
          cnt[s[l]]--;
          l++;
        }
        if (r - l + 1 < ans) {
          ans = r - l + 1;
          bestl = l;
        }
      }
      r++;
    }
    if (ans == INT_MAX) return "";
    return s.substr(bestl, ans);
  }
};