/*
  320_v1.cpp
  Generalized Abbreviation

  My first submission got WA since I returned an empty vector for the case where
  word is an empty string.
*/

class Solution {
 public:
  vector<string> generateAbbreviations(string word) {
    vector<string> ret;
    if (word.size() == 0) {
      ret.push_back(word);
      return ret;
    }
    if (word.size() == 1) {
      ret.push_back(word);
      ret.push_back("1");
      return ret;
    }
    vector<string> subRet = generateAbbreviations(word.substr(1));
    for (int i = 0; i < subRet.size(); i++) ret.push_back(word[0] + subRet[i]);
    for (int i = 0; i < subRet.size(); i++) {
      int numVal = 0;
      for (int j = 0; j < subRet[i].size(); j++) {
        if (!isdigit(subRet[i][j])) {
          ret.push_back(to_string(numVal + 1) + subRet[i].substr(j));
          numVal = 0;
          break;
        } else
          numVal = numVal * 10 + (subRet[i][j] - '0');
      }
      if (numVal) ret.push_back(to_string(numVal + 1));
    }
    return ret;
  }
};