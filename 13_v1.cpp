/*
  13_v1.cpp
  Roman to Integer
*/

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> m = {{'I', 1},
                                  {'V', 5},
                                  {'X', 10},
                                  {'L', 50},
                                  {'C', 100},
                                  {'D', 500},
                                  {'M', 1000}};
    int len = s.size(), ans = 0;
    for (int i = 0; i < len; i++) {
      if (i == len - 1 || m[s[i]] >= m[s[i + 1]])
        ans += m[s[i]];
      else
        ans -= m[s[i]];
    }
    return ans;
  }
};