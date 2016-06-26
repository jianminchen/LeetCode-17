/*
  336_v2_im.cpp
  Palindrome Pairs
*/

class Solution {
 private:
  bool isPalindrome(string str) {
    int l = 0, r = (int)str.size() - 1;
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
    unordered_map<string, vector<int>> suffixMap;
    for (int i = 0; i < words.size(); i++) {
      string prefix = "", suffix = words[i];
      for (int j = 0; j <= words[i].size(); j++) {
        if (isPalindrome(prefix)) suffixMap[suffix].push_back(i);
        if (j == words[i].size()) break;
        prefix += words[i][j];
        suffix = suffix.substr(1);
      }
    }
    for (int i = 0; i < words.size(); i++) {
      string prefix = words[i], suffix = "";
      for (int j = words[i].size() - 1; j >= -1; j--) {
        if (isPalindrome(suffix)) {
          string reversedPrefix = prefix;
          reverse(reversedPrefix.begin(), reversedPrefix.end());
          if (suffixMap.count(reversedPrefix)) {
            for (int k = 0; k < suffixMap[reversedPrefix].size(); k++) {
              int idx = suffixMap[reversedPrefix][k];
              if (i == idx) continue;
              if (suffix == "" || words[idx].size() == reversedPrefix.size())
                ret.emplace_back(vector<int>{i, idx});
            }
          }
        }
        if (j == -1) break;
        prefix = prefix.substr(0, prefix.size() - 1);
        suffix = words[i][j] + suffix;
      }
    }
    return ret;
  }
};