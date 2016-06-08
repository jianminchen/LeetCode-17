/*
  247_v1.cpp
  Strobogrammatic Number II

  Both my first and second submissions failed because I didn't consider the case
  of leading zeroes fully. My first solution failed on the case where n == 1, I
  was returning 1 and 8 but the correct answer should be 0, 1 and 8. So I've
  added 0 into the map m and then quickly added the condition "if (it.first ==
  0) continue;" to avoid generating the case where we have a leading zero.
  However, although we should not generate a number with a leading zero, it is
  perfectly OK if that zero appears in the middle of the number. So I've fixed
  this issue in my third submission.
*/

class Solution {
 private:
  unordered_map<int, int> m = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};

  vector<string> solve(int n, bool canHaveLeadingZero) {
    vector<string> ret;
    if (n == 0) return ret;
    if (n == 1) {
      for (auto it : m) {
        if (it.first == it.second) ret.push_back(to_string(it.first));
      }
      return ret;
    }
    vector<string> vs = solve(n - 2, true);
    for (auto it : m) {
      if (!canHaveLeadingZero && it.first == 0) continue;
      if (vs.size() == 0)
        ret.push_back(to_string(it.first) + to_string(it.second));
      else {
        for (auto str : vs)
          ret.push_back(to_string(it.first) + str + to_string(it.second));
      }
    }
    return ret;
  }

 public:
  vector<string> findStrobogrammatic(int n) { return solve(n, false); }
};