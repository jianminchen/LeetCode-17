/*
  38_v1.cpp
  Count and Say
*/

class Solution {
 public:
  string countAndSay(int n) {
    vector<string> vs;
    vs.push_back("1");
    for (int i = 2; i <= n; i++) {
      string prev = vs.back();
      string str = "";
      char ch = prev[0];
      int cnt = 1;
      for (int j = 1; j < prev.size(); j++) {
        if (prev[j] == ch)
          cnt++;
        else {
          str += to_string(cnt);
          str += ch;
          cnt = 1;
          ch = prev[j];
        }
      }
      str += to_string(cnt);
      str += ch;
      vs.push_back(str);
    }
    return vs.back();
  }
};