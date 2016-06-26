/*
  68_v2.cpp
  Text Justification
*/

class Solution {
 private:
  string justify(vector<string>& words, int start, int end,
                 bool shouldLeftJustify, int maxWidth) {
    int numSlots = end - start;
    string ret = "";

    if (shouldLeftJustify || numSlots == 0) {
      for (int i = start; i < end; i++) ret += (words[i] + ' ');
      ret += words[end];
      ret += string(maxWidth - ret.size(), ' ');
      return ret;
    }

    int wordLenSum = 0;
    for (int i = start; i <= end; i++) wordLenSum += words[i].size();
    int numSpaces = maxWidth - wordLenSum;

    for (int i = 0; i < end - start; i++) {
      if (i < numSpaces % numSlots)
        ret += words[start + i] + string(numSpaces / numSlots + 1, ' ');
      else
        ret += words[start + i] + string(numSpaces / numSlots, ' ');
    }
    ret += words[end];
    return ret;
  }

 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;

    int start = 0, end = 0, currWidth = words[0].size();
    for (int i = 1; i < words.size(); i++) {
      if (currWidth + 1 + words[i].size() <= maxWidth) {
        end = i;
        currWidth += (1 + words[i].size());
      } else {
        ret.push_back(justify(words, start, end, false, maxWidth));
        start = end = i;
        currWidth = words[i].size();
      }
    }
    ret.push_back(justify(words, start, end, true, maxWidth));
    return ret;
  }
};