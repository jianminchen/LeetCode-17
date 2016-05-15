/*
  290_v1.cpp
  Word Pattern

  My first submission got WA since I moved "cnt++;" inside the preceding if
  block.
*/

class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    int num[26];
    memset(num, -1, sizeof(num));
    vector<int> v1, v2;
    for (int i = 0; i < pattern.size(); i++) {
      if (num[pattern[i] - 'a'] == -1) num[pattern[i] - 'a'] = i;
      v1.push_back(num[pattern[i] - 'a']);
    }
    string word = "";
    unordered_map<string, int> m;
    int cnt = 0;
    str += ' ';
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == ' ') {
        if (m.find(word) == m.end()) m[word] = cnt;
        cnt++;
        v2.push_back(m[word]);
        word = "";
      } else {
        word += str[i];
      }
    }

    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); i++) {
      cout << v1[i] << " " << v2[i] << endl;
      if (v1[i] != v2[i]) return false;
    }
    return true;
  }
};