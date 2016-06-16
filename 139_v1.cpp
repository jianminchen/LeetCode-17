/*
  139_v1.cpp
  Word Break
*/

class Solution {
 public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    bool f[s.size() + 1];
    memset(f, false, sizeof(f));
    f[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      string tmp = "";
      for (int j = i - 1; j >= 0; j--) {
        tmp = s[j] + tmp;
        if (f[j] && (wordDict.find(tmp) != wordDict.end())) {
          // cout << j << " " << tmp << " " << i << endl;
          f[i] = true;
          break;
        }
      }
    }
    return f[s.size()];
  }
};