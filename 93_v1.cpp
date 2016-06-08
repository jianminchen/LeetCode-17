/*
  93_v1.cpp
  Restore IP Addresses

  My first submission got WA since I didn't consider the case of leading zeroes.
  For example, for the input s = "010010", I'm returning invalid IP addresses
  like "0.1.0.10" and "1.0.0.10".
*/

class Solution {
 private:
  void dfs(int depth, string s, vector<int>& v, vector<string>& ret) {
    if (depth == s.size()) {
      if (v.size() == 4) {
        string str = "";
        for (int i = 0; i < 3; i++) str += to_string(v[i]) + ".";
        str += to_string(v[3]);
        ret.push_back(str);
      }
      return;
    }
    if (v.size() == 4) return;
    int val = 0;
    if (s[depth] == '0') {
      v.push_back(0);
      dfs(depth + 1, s, v, ret);
      v.pop_back();
    } else {
      for (int i = depth; i < s.size(); i++) {
        val = val * 10 + (s[i] - '0');
        if (val > 255) break;
        v.push_back(val);
        dfs(i + 1, s, v, ret);
        v.pop_back();
      }
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    vector<int> v;
    dfs(0, s, v, ret);
    return ret;
  }
};