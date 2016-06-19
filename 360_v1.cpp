/*
  360_v1.cpp
  Sort Transformed Array

  My first submission got WA because I used "res > l.back()" instead of "res >=
  l.back()". Anyway, my solution is really complex compared to the currently
  most voted solution in the discussion. I'm actually manually splitting the
  results into two parts and then merged the two parts. In fact we don't need to
  do so. We only need to check sgn(a), thus we can know whether the maximum or
  the minimum values appeared on nums[0] / nums.back(). If we know that
  information then we can merge easily.
*/

class Solution {
 public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    vector<int> ret;
    if (a == 0) {
      list<int> l;
      for (int val : nums) {
        int res = a * val * val + b * val + c;
        if (l.empty() || res >= l.back())
          l.push_back(res);
        else
          l.push_front(res);
      }
      for (int val : l) ret.push_back(val);
      return ret;
    }
    list<int> l1, l2;
    double tmp = -1.0 * b / (2 * a);
    for (int val : nums) {
      int res = a * val * val + b * val + c;
      if (val < tmp) {
        if (l1.empty() || res >= l1.back())
          l1.push_back(res);
        else
          l1.push_front(res);
      } else {
        if (l2.empty() || res >= l2.back())
          l2.push_back(res);
        else
          l2.push_front(res);
      }
    }
    auto p1 = l1.begin(), p2 = l2.begin();
    while (p1 != l1.end() && p2 != l2.end()) {
      if (*p1 < *p2)
        ret.push_back(*(p1++));
      else
        ret.push_back(*(p2++));
    }
    while (p1 != l1.end()) ret.push_back(*(p1++));
    while (p2 != l2.end()) ret.push_back(*(p2++));
    return ret;
  }
};