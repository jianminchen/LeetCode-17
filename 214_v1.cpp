/*
  214_v1.cpp
  Shortest Palindrome

  Initially I was using vector<string> hash[PRIME] and this solution definitely
  got both TLE and MLE for my first submission. Then my second submission got
  RTE because LeetCode won't allow vector<string> hash[1000003]; My third and my
  fourth submission WAed because I was trying not to handle hash collision at
  all [in hopes of it can just get accepted].
*/

class Solution {
 private:
  static const int PRIME = 100003;
  vector<int> hash[PRIME];

 public:
  string shortestPalindrome(string s) {
    int hashVal = 0;
    for (int i = 0; i < s.size(); i++) {
      hashVal = (hashVal * 26 + s[i] - 'a' + 1) % PRIME;
      hash[hashVal].push_back(i);
    }
    hashVal = 0;
    int pow = 1;
    int maxPalindromicPrefixLen = 0;
    for (int i = 0; i < s.size(); i++) {
      hashVal = ((s[i] - 'a' + 1) * pow + hashVal) % PRIME;
      pow = (pow * 26) % PRIME;
      if (hash[hashVal].size() == 0) continue;
      for (int j = 0; j < hash[hashVal].size(); j++) {
        if (hash[hashVal][j] == i) {
          maxPalindromicPrefixLen = i + 1;
          break;
        }
      }
    }
    string ans = "";
    for (int i = s.size() - 1; i >= maxPalindromicPrefixLen; i--) ans += s[i];
    ans += s;
    return ans;
  }
};