/*
  151_v1.cpp
  Reverse Words in a String

  My first four submissions got WA. I forgot to add "r--;" after "while (r <
  lenS && s[r] != ' ') r++;" and initially I've written "l = wordR + 1;" after
  swapping each word. But at that time wordR has already changed.
*/

class Solution {
 public:
  void reverseWords(string &s) {
    int lenS = s.size();
    if (lenS == 0) return;
    int l = 0, r = lenS - 1;
    while (l < r) swap(s[l++], s[r--]);
    cout << s << endl;
    l = 0, r = 0;
    while (l < lenS) {
      if (s[l] != ' ') {
        r = l;
        while (r < lenS && s[r] != ' ') r++;
        r--;
        int wordL = l, wordR = r;
        while (wordL < wordR) swap(s[wordL++], s[wordR--]);
        l = r + 1;
      } else {
        l++;
      }
    }
    cout << s << endl;
    int p = 0;
    for (int i = 0; i < lenS; i++) {
      if (s[i] != ' ')
        s[p++] = s[i];
      else {
        if (i >= 1 && s[i - 1] != ' ') s[p++] = s[i];
      }
    }
    cout << s << endl;
    if (s[p - 1] != ' ')
      s = s.substr(0, p);
    else
      s = s.substr(0, p - 1);
    cout << s << endl;
  }
};