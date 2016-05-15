/*
  205_v1.cpp
  Isomorphic Strings

  Initially I thought it's just a matter of "count and sort" but this idea
  failed on the data "aba" and "baa". Then I thought it's a matter of "count and
  compare" and found this idea failed on "abba" and "abab". Later I've figured
  out it's a matter of "hash using the index and compare". I've got 3 WAs. My
  two incorrect ideas contribute to my first two WAs and my third WA is due to a
  typo.
*/

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    int num1[255] = {0}, num2[255] = {0};
    for (int i = 0; i < s.size(); i++) {
      if (num1[s[i]] == 0) num1[s[i]] = i;
      if (num2[t[i]] == 0) num2[t[i]] = i;
    }
    for (int i = 0; i < s.size(); i++)
      if (num1[s[i]] != num2[t[i]]) return false;
    return true;
  }
};