/*
  282_v1.cpp
  Expression Add Operators

  My first submission just tries to construct all valid paths and then evaluate
  the expression in the final call when pos == num.size(). This gave me TLE.
  I've found we don't actually need to wait till the end to evaluate the
  expression value and we can evaluate the value on-the-fly.
*/

class Solution {
 private:
  void search(vector<string>& ret, string path, string num, int target, int pos,
              long long eval, long long multed) {
    if (pos == num.size()) {
      if (target == eval) ret.push_back(path);
      return;
    }
    long long currNum = 0;
    for (int i = pos; i < num.size(); i++) {
      if (i != pos && num[pos] == '0') break;
      currNum = currNum * 10 + num[i] - '0';
      if (pos == 0)
        search(ret, path + to_string(currNum), num, target, i + 1, currNum,
               currNum);
      else {
        search(ret, path + "+" + to_string(currNum), num, target, i + 1,
               eval + currNum, currNum);
        search(ret, path + "-" + to_string(currNum), num, target, i + 1,
               eval - currNum, -currNum);
        search(ret, path + "*" + to_string(currNum), num, target, i + 1,
               eval - multed + multed * currNum, multed * currNum);
      }
    }
  }

 public:
  vector<string> addOperators(string num, int target) {
    vector<string> ret;
    if (num.size() == 0) return ret;
    search(ret, "", num, target, 0, 0, 0);
    return ret;
  }
};