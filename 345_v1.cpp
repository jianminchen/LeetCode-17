/*
  345_v1.cpp
  Reverse Vowels of a String
*/

class Solution {
  bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  string reverseVowels(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (!isVowel(s[l]) && l < r) l++;
      while (!isVowel(s[r]) && l < r) r--;
      if (l < r) swap(s[l], s[r]);
      l++;
      r--;
    }
    return s;
  }
};