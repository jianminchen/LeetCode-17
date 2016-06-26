/*
  367_v1.cpp
  Valid Perfect Square

  My first submission got TLE because of a binary search issue. Normally when we
  set "lo = mid", in the special case where hi - lo == 1, if we set lo = mid in
  the next iteration, then the size of the interval [lo, hi] won't shrink and so
  the while loop would get stuck. The solution is to "shift" mid to right by 1.
  So instead of using "mid = lo + (hi - lo) / 2" we write "mid = lo + (hi - lo)
  / 2 + 1".
*/

class Solution {
 public:
  bool isPerfectSquare(int num) {
    int lo = 1, hi = num, mid;
    while (lo < hi) {
      mid = lo + (hi - lo) / 2 + 1;
      if ((long long)mid * mid <= num)
        lo = mid;
      else
        hi = mid - 1;
    }
    if ((long long)lo * lo == num) return true;
    return false;
  }
};