/*
  186_v1.cpp
  Reverse Words in a String II

  My first submission got WA since I've written something like "while (r <
  s.size() && s[r++] != ' ');" which is intrinsically different from "while (r <
  s.size() && s[r] != ' ') r++;".
*/

class Solution {
 public:
  void reverseWords(string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      swap(s[l], s[r]);
      l++;
      r--;
    }
    l = 0;
    while (l < s.size()) {
      r = l;
      while (r < s.size() && s[r] != ' ') r++;
      int newL = r + 1;
      r--;
      while (l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
      }
      l = newL;
    }
  }
};