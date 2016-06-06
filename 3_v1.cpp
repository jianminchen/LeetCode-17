/*
  3_v1.cpp
  Longest Substring Without Repeating Characters

  My first submission got WA again because of the condition of the while loop.
*/

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int len = s.size();
    if (len == 0) return 0;
    int l = 0, r = 0, cnt[256] = {0}, ans = 0;
    while (l < len && r < len) {
      cnt[s[r]]++;
      while (cnt[s[r]] > 1) {
        cnt[s[l]]--;
        l++;
      }
      ans = max(ans, r - l + 1);
      r++;
    }
    return ans;
  }
};