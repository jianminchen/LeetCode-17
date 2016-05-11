/*
  246_v1.cpp
  Strobogrammatic Number

  My first submission got WA since I used "while (l < r)" but here we should use
  "while (l <= r)" since even when we only have a single digit remaining it can
  return false.
*/

class Solution {
 public:
  bool isStrobogrammatic(string num) {
    int l = 0, r = num.size() - 1;
    while (l <= r) {
      if (num[l] == num[r]) {
        if (num[l] != '0' && num[l] != '1' && num[l] != '8') return false;
      } else {
        if ((num[l] == '6' && num[r] == '9') ||
            (num[l] == '9' && num[r] == '6'))
          ;
        else
          return false;
      }
      l++;
      r--;
    }
    return true;
  }
};