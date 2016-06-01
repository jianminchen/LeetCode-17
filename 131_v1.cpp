/*
  131_v1.cpp
  Palindrome Partitioning

  I've made an indexing mistake in my first submission and got WA.
*/

class Solution {
 public:
  vector<vector<string>> ret;

  void dfs(int curr, int maxDepth, string s, vector<string>& partitions,
           vector<vector<bool>>& isPalindrome) {
    if (curr == maxDepth) ret.push_back(partitions);
    for (int i = curr; i < maxDepth; i++) {
      if (isPalindrome[curr][i]) {
        partitions.push_back(s.substr(curr, i - curr + 1));
        dfs(i + 1, maxDepth, s, partitions, isPalindrome);
        partitions.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    int len = s.size();
    vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));
    for (int i = 0; i < s.size(); i++) isPalindrome[i][i] = true;
    for (int i = 0; i + 1 < s.size(); i++)
      if (s[i] == s[i + 1]) isPalindrome[i][i + 1] = true;
    for (int len = 2; len < s.size(); len++) {
      for (int i = 0; i + len < s.size(); i++) {
        if (s[i] == s[i + len] && isPalindrome[i + 1][i + len - 1])
          isPalindrome[i][i + len] = true;
      }
    }
    vector<string> partitions;
    dfs(0, len, s, partitions, isPalindrome);
    return ret;
  }
};