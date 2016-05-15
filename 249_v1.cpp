/*
  249_v1.cpp
  Group Shifted Strings
*/

class Solution {
 public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < strings.size(); i++) {
      string originalStr = strings[i];
      char firstCh = strings[i][0];
      for (int j = 0; j < strings[i].size(); j++)
        strings[i][j] = ((strings[i][j] - firstCh + 26) % 26) + 'a';
      m[strings[i]].push_back(originalStr);
    }
    vector<vector<string>> ret;
    for (auto it : m) {
      vector<string> vs = it.second;
      sort(vs.begin(), vs.end());
      ret.push_back(vs);
    }
    return ret;
  }
};