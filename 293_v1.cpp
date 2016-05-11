/*
  293_v1.cpp
  Flip Game
*/

class Solution {
 public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> ret;
    for (int i = 0; i + 1 < s.size(); i++) {
      string tmp = s;
      if (s[i] == '+' && s[i + 1] == '+') {
        tmp[i] = tmp[i + 1] = '-';
        ret.push_back(tmp);
      }
    }
    return ret;
  }
};