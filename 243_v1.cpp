/*
  243_v1.cpp
  Shortest Word Distance
*/

class Solution {
 public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int pos1 = -1, pos2 = -1, ans = INT_MAX;
    for (int i = 0; i < words.size(); i++) {
      if (words[i] == word1) {
        pos1 = i;
        if (pos2 != -1 && pos1 - pos2 < ans) ans = pos1 - pos2;
      } else if (words[i] == word2) {
        pos2 = i;
        if (pos1 != -1 && pos2 - pos1 < ans) ans = pos2 - pos1;
      }
    }
    return ans;
  }
};