/*
  140_v2.cpp
  Word Break II
*/

class Solution {
 public:
  vector<string> search(string s, int len, unordered_set<string>& wordDict,
                        vector<bool>& visited, vector<vector<string>>& f) {
    if (visited[len]) return f[len];
    visited[len] = true;
    vector<string> ret;
    if (len == 0) {
      ret.push_back("");
      return f[len] = ret;
    }
    string tmp = "";
    for (int i = len - 1; i >= 0; i--) {
      tmp = s[i] + tmp;
      if (wordDict.find(tmp) != wordDict.end()) {
        vector<string> vs = search(s, i, wordDict, visited, f);
        for (string str : vs) {
          if (str == "")
            ret.push_back(tmp);
          else
            ret.push_back(str + " " + tmp);
        }
      }
    }
    return f[len] = ret;
  }
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int len = s.size();
    vector<bool> visited(len + 1, false);
    vector<vector<string>> f(len + 1, vector<string>());
    return search(s, len, wordDict, visited, f);
  }
};