/*
  340_v1.cpp
  Longest Substring with At Most K Distinct Characters

  My first submission got WA because I didn't consider the special case where
  s.size() == 0. My second submission again got WA since my while loop condition
  is incorrect, it should be while (l != len - 1 && r != len - 1) instead of
  while (l < len && r < len).
*/

class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int len = s.size();
    if (len == 0) return 0;
    if (k == 0) return 0;
    int cnt[256], numchar = 0;
    memset(cnt, 0, sizeof(cnt));
    int l = 0, r = 0, maxlen = 1;
    cnt[s[l]]++;
    numchar = 1;
    while (l != len - 1 && r != len - 1) {
      r++;
      if (cnt[s[r]] == 0) numchar++;
      cnt[s[r]]++;
      // cout << l << " " << r << " " << numchar << endl;
      while (numchar > k) {
        if (cnt[s[l]] == 1) numchar--;
        cnt[s[l]]--;
        l++;
      }
      maxlen = max(maxlen, r - l + 1);
      // cout << l << " " << r << " " << numchar << endl;
    }
    return maxlen;
  }
};