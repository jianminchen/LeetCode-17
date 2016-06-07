/*
  159_v1.cpp
  Longest Substring with At Most Two Distinct Characters
*/

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    if (s.size() == 0) return 0;
    int cnt[256], numChar = 0;
    memset(cnt, 0, sizeof(cnt));
    int l = 0, r = 0, len = s.size(), ans = 0;
    while (l < len && r < len) {
      cnt[s[r]]++;
      if (cnt[s[r]] == 1) numChar++;
      while (numChar > 2) {
        cnt[s[l]]--;
        if (cnt[s[l]] == 0) numChar--;
        l++;
      }
      ans = max(ans, r - l + 1);
      r++;
    }
    return ans;
  }
};