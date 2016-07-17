/*
  374_v1.cpp
  Guess Number Higher or Lower
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    int lo = 1, hi = n;
    while (hi - lo > 0) {
      int mid = lo + (hi - lo) / 2;
      int ret = guess(mid);
      if (ret == 0)
        return mid;
      else if (ret == -1)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    return lo;
  }
};