/*
  69_v1.cpp
  Sqrt(x)
*/

class Solution {
 public:
  int mySqrt(int x) {
    int lo = 0, hi = x, mid;
    while (hi - lo > 1) {
      mid = lo + (hi - lo) / 2;
      long long tmp = (long long)mid * mid;
      if (tmp == x)
        return mid;
      else if (tmp > x)
        hi = mid - 1;
      else
        lo = mid;
    }
    if (hi * hi <= x) return hi;
    return lo;
  }
};