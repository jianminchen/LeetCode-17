/*
  72_v1.cpp
  Edit Distance

  My first submission got WA since I wrote something like this "min(f[i - 1][j],
  f[i][j - 1], f[i - 1][j - 1])" and the CE message says "required from here".
  It was not indicative at all so I spent a long time figuring out the issue.
  Then my second submission got WA since I forgot to initialize the boundary
  case for f[0][i] and f[i][0].
*/

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size(), len2 = word2.size();
    int f[len1 + 1][len2 + 1];
    f[0][0] = 0;
    for (int i = 1; i <= len1; i++) f[i][0] = i;
    for (int i = 1; i <= len2; i++) f[0][i] = i;
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (word1[i - 1] == word2[j - 1])
          f[i][j] = f[i - 1][j - 1];
        else
          f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
      }
    }
    return f[len1][len2];
  }
};