/*
  336_v2.cpp
  Palindrome Pairs

  My first two submissions both got WA and basically this is because I haven't
  thought through the whole algorithm very clearly.

  If we concatenate two strings S1, S2 and the concatenated string becomes a
  palindrome, then basically it falls into the following two categories: S11 +
  S12 + S2, where S12 is a suffix of S1 and S12 itself is a palindrome; S1 + S21
  + S22, where S21 is a prefix of S2 and S21 itself is a palindrome.

  For each word, we will check all its prefix (from the empty string all the way
  to the full word) and validate whether the prefix it is a palindrome
  (corresponds to S21 in the previous description). If we've found a palindromic
  prefix, we'll insert the remaining suffix to a hash map.

  Next, based on the previous discussion we can just enumerate the two cases,
  for each string S1 we can just check whether its reverse exists in the
  hashmap. This covers the S1 + S21 + S22 case. Then we also need to check the
  S11 + S12 + S2 by checking palindromic suffixes of S1. Combining these two
  parts gives us the final answer.

  The time complexity of this approach is O(NL^2) where N is the number of
  strings and L is the average string length.
*/

class Solution {
 private:
  bool isPalindrome(string str) {
    int l = 0, r = str.size() - 1;
    while (l < r) {
      if (str[l] != str[r]) return false;
      l++;
      r--;
    }
    return true;
  }

 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ret;
    unordered_map<string, vector<pair<int, bool>>> wordSuffixMap;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j <= words[i].size(); j++) {
        string prefix = words[i].substr(0, j);
        if (isPalindrome(prefix)) {
          string suffix = words[i].substr(j);
          wordSuffixMap[suffix].emplace_back(i, j == 0);
        }
      }
    }
    for (int i = 0; i < words.size(); i++) {
      string word = words[i];
      for (int j = 0; j <= word.size(); j++) {
        string wordSuffix = word.substr(j);
        if (isPalindrome(wordSuffix)) {
          string reversedPrefix = word.substr(0, j);
          reverse(reversedPrefix.begin(), reversedPrefix.end());
          if (wordSuffixMap.count(reversedPrefix)) {
            for (int k = 0; k < wordSuffixMap[reversedPrefix].size(); k++) {
              auto p = wordSuffixMap[reversedPrefix][k];
              int idx = p.first;
              bool isFullWord = p.second;
              if (j == word.size()) {
                if (i != idx) ret.push_back(vector<int>{i, idx});
              } else {
                if (isFullWord) ret.push_back(vector<int>{i, idx});
              }
            }
          }
        }
      }
    }
    return ret;
  }
};