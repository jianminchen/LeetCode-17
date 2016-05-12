/*
  269_v1.cpp
  Alien Dictionary
*/

class Solution {
 public:
  string alienOrder(vector<string>& words) {
    bool gr[26][26] = {0}, appeared[26] = {false};
    int cnt = 0;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words[i].size(); j++) {
        appeared[words[i][j] - 'a'] = true;
      }
    }
    for (int i = 0; i < words.size() - 1; i++) {
      for (int j = 0; j < min(words[i].size(), words[i + 1].size()); j++) {
        if (words[i][j] != words[i + 1][j]) {
          gr[words[i][j] - 'a'][words[i + 1][j] - 'a'] = true;
          break;
        }
      }
    }
    queue<int> q;
    int inDegree[26] = {0};
    string ret = "";
    for (int i = 0; i < 26; i++) {
      if (appeared[i]) {
        cnt++;
        for (int j = 0; j < 26; j++) {
          if (gr[j][i]) inDegree[i]++;
        }
        if (inDegree[i] == 0) q.push(i);
      }
    }
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      ret += (char)(curr + 'a');
      for (int i = 0; i < 26; i++) {
        if (gr[curr][i]) {
          inDegree[i]--;
          if (inDegree[i] == 0) q.push(i);
        }
      }
    }
    if (ret.size() == cnt) return ret;
    return "";
  }
};