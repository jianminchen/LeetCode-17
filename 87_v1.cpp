/*
  87_v1.cpp
  Scramble String
*/

class Solution {
 private:
  string s1, s2;
  vector<vector<vector<int>>> cache;
  bool dp(int len, int idx1, int idx2) {
    if (cache[len][idx1][idx2] != -1) return cache[len][idx1][idx2];
    if (len == 1) {
      int res = (s1[idx1] == s2[idx2]);
      return cache[len][idx1][idx2] = res;
    }
    int res = 0;
    for (int i = 1; i < len; i++) {
      if (dp(i, idx1, idx2) && dp(len - i, idx1 + i, idx2 + i))
        return cache[len][idx1][idx2] = 1;
      if (dp(i, idx1, idx2 + len - i) && dp(len - i, idx1 + i, idx2))
        return cache[len][idx1][idx2] = 1;
    }
    return cache[len][idx1][idx2] = 0;
  }

 public:
  bool isScramble(string s1, string s2) {
    this->s1 = s1;
    this->s2 = s2;
    int len = s1.size();
    cache.resize(len + 1);
    for (int i = 0; i <= len; i++) {
      cache[i].resize(len);
      for (int j = 0; j < len; j++) {
        cache[i][j].resize(len);
        for (int k = 0; k < len; k++) cache[i][j][k] = -1;
      }
    }
    return dp(len, 0, 0);
  }
};