/*
  14_v1.cpp
  Longest Common Prefix
*/

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string ret = "";
    if (strs.size() == 0) return ret;
    for (int i = 0; i < strs[0].size(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (i >= strs[j].size() || strs[j][i] != strs[0][i]) return ret;
      }
      ret += strs[0][i];
    }
    return ret;
  }
};