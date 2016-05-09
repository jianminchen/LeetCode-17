/*
  140_v1.cpp
  Word Break II

  My first four submissions either get TLE or MLE because I'm using bottom-up DP
  instead of top-down DP for this problem. Normally it doesn't matter much for
  this particular problem it matters A LOT. The bad thing here is I haven't
  really checked the test cases so I thought it was a matter of constant
  factors.

  Consider an example like this:

  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  ["aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"]

  We know that the output should be an empty vector but if we follow a bottom-up
  approach it means we would easily get MLE or TLE before we reach the "baa"
  part because at that time the vector<string> for a particular f[i] would
  probably be quite huge.

  So here finally I've used a bool vector to quickly rule out all the "invalid
  cases" and then follow the traditional bottom-up approach. A better idea is
  to use a top-down approach.
*/

class Solution {
 public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int len = s.size();
    bool f[len + 1] = {false};
    f[0] = true;
    for (int i = 1; i <= len; i++) {
      string tmp = "";
      for (int j = i - 1; j >= 0; j--) {
        tmp = s[j] + tmp;
        if (wordDict.find(tmp) != wordDict.end()) f[i] |= f[j];
      }
    }
    if (!f[len]) {
      return vector<string>();
    }
    vector<string> g[len + 1];
    g[0].push_back("");
    for (int i = 1; i <= len; i++) {
      string tmp = "";
      for (int j = i - 1; j >= 0; j--) {
        tmp = s[j] + tmp;
        // cout << i << " " << tmp << endl;
        if (wordDict.find(tmp) != wordDict.end()) {
          for (int k = 0; k < g[j].size(); k++) {
            if (g[j][k] == "")
              g[i].push_back(tmp);
            else
              g[i].push_back(g[j][k] + " " + tmp);
          }
        }
      }
      cout << g[i].size() << endl;
    }
    return g[len];
  }
};