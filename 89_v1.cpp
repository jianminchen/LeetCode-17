/*
  89_v1.cpp
  Gray Code
*/

class Solution {
 public:
  vector<int> grayCode(int n) {
    if (n == 0) return vector<int>{0};
    vector<int> v = grayCode(n - 1);
    vector<int> ret;
    for (int i = 0; i < v.size(); i++) ret.push_back(v[i]);
    for (int i = v.size() - 1; i >= 0; i--)
      ret.push_back(v[i] + (1 << (n - 1)));
    return ret;
  }
};