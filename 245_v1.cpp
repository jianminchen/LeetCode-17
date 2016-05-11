/*
  245_v1.cpp
  Shortest Word Distance III
*/

class Solution {
 public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int ans = INT_MAX, p1 = -1, p2 = -1;
    if (word1 == word2) {
      for (int i = 0; i < words.size(); i++) {
        if (words[i] == word1) {
          if (p1 != -1) ans = min(ans, i - p1);
          p1 = i;
        }
      }
    } else {
      for (int i = 0; i < words.size(); i++) {
        if (words[i] == word1) {
          if (p2 != -1) ans = min(ans, i - p2);
          p1 = i;
        } else if (words[i] == word2) {
          if (p1 != -1) ans = min(ans, i - p1);
          p2 = i;
        }
      }
    }
    return ans;
  }
};