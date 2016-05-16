/*
  318_v1.cpp
  Maximum Product of Word Lengths
*/

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    unordered_map<int, int> m;
    for (int i = 0; i < words.size(); i++) {
      int mask = 0;
      for (int j = 0; j < words[i].size(); j++)
        mask |= (1 << (words[i][j] - 'a'));
      m[mask] = max(m[mask], (int)words[i].size());
    }
    int ans = 0;
    for (auto m1 : m) {
      for (auto m2 : m) {
        if ((m1.first & m2.first) == 0) ans = max(ans, m1.second * m2.second);
      }
    }
    return ans;
  }
};