/*
  266_v1.cpp
  Palindrome Permutation
*/

class Solution {
 public:
  bool canPermutePalindrome(string s) {
    sort(s.begin(), s.end());
    int cnt = 1, numOdd = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1])
        cnt++;
      else {
        if (cnt % 2 == 1) numOdd++;
        cnt = 1;
      }
    }
    if (cnt % 2 == 1) numOdd++;
    return numOdd <= 1;
  }
};