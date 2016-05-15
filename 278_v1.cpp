/*
  278_v1.cpp
  First Bad Version

  My first submission got WA because of a typo "while (hi - lo > 1)". My second
  submission got WA because of the overflow issue "mid = (lo + hi) / 2;".
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int lo = 1, hi = n, mid;
    while (hi - lo >= 1) {
      mid = lo + (hi - lo) / 2;
      if (isBadVersion(mid))
        hi = mid;
      else
        lo = mid + 1;
    }
    return lo;
  }
};