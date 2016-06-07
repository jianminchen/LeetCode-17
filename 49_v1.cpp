/*
  49_v1.cpp
  Group Anagrams
*/

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < strs.size(); i++) {
      string tmp = strs[i];
      sort(tmp.begin(), tmp.end());
      m[tmp].push_back(strs[i]);
    }
    vector<vector<string>> ret;
    for (auto it : m) ret.push_back(it.second);
    return ret;
  }
};