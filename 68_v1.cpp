/*
  68_v1.cpp
  Text Justification

  My first submission got WA because of a stupid but a bit tricky mistake.
  Previously in the special case (leftJustify or l == r) what I wrote was "for
  (int i = 0; i < maxWidth - ret.size(); i++) ret += ' ';". However, ret.size()
  gets changed each time as we append more spaces. So we need to store numSpace
  first.
*/

class Solution {
 public:
  string justify(vector<string>& words, int l, int r, int maxWidth,
                 bool leftJustify) {
    string ret = "";
    if (leftJustify || l == r) {
      ret = words[l];
      for (int i = l + 1; i <= r; i++) ret += " " + words[i];
      int numSpace = maxWidth - ret.size();
      for (int i = 0; i < numSpace; i++) ret += ' ';
      return ret;
    } else {
      int numGap = r - l, lenSum = 0;
      for (int i = l; i <= r; i++) lenSum += words[i].size();
      int numSpace = maxWidth - lenSum;
      ret = words[l];
      for (int i = l + 1; i <= r; i++) {
        if (i - l - 1 < numSpace % numGap) {
          for (int j = 0; j < numSpace / numGap + 1; j++) ret += ' ';
        } else {
          for (int j = 0; j < numSpace / numGap; j++) ret += ' ';
        }
        ret += words[i];
      }
      return ret;
    }
  }
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
    int l = 0, r = 0, sum = words[0].size();
    for (int i = 1; i < words.size(); i++) {
      if (sum + 1 + words[i].size() <= maxWidth) {
        sum += words[i].size() + 1;
        r = i;
      } else {
        ret.push_back(justify(words, l, r, maxWidth, false));
        l = i;
        r = i;
        sum = words[i].size();
      }
    }
    ret.push_back(justify(words, l, r, maxWidth, true));
    return ret;
  }
};