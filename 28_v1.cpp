/*
  28_v1.cpp
  Implement strStr()

  I've no idea why when needle == "" we should return 0.
*/

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle == "") return 0;
    for (int i = 0; i + needle.size() - 1 < haystack.size(); i++) {
      bool flag = true;
      for (int j = 0; j < needle.size(); j++) {
        if (haystack[i + j] != needle[j]) {
          flag = false;
          break;
        }
      }
      if (flag) return i;
    }
    return -1;
  }
};