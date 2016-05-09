/*
  6_v1.cpp
  ZigZag Conversion

  My first submission got WA because I didn't handle the special case where
  numRows == 1.
*/

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string ret[numRows];
    int r = 0, flag = 1;
    for (int i = 0; i < s.size(); i++) {
      ret[r] += s[i];
      if (r == numRows - 1)
        flag = -1;
      else if (r == 0)
        flag = 1;
      r += flag;
    }
    string ans = "";
    for (int i = 0; i < numRows; i++) ans += ret[i];
    return ans;
  }
};