/*
  168_v1.cpp
  Excel Sheet Column Title
*/

class Solution {
 public:
  string convertToTitle(int n) {
    string ret = "";
    while (n) {
      int val = (n % 26 == 0 ? 26 : n % 26);
      ret = (char)(val + 'A' - 1) + ret;
      n -= val;
      n /= 26;
    }
    return ret;
  }
};