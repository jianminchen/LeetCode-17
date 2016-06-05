/*
  50_v1.cpp
  Pow(x, n)

  My first submission got WA due to the corner case n = INT_MIN.
*/

class Solution {
  double myPowLL(double x, long long n) {
    if (n < 0) return 1.0 / myPowLL(x, -n);
    double ans = 1, tmpVal = x;
    while (n) {
      if (n % 2 == 1) ans *= tmpVal;
      tmpVal *= tmpVal;
      n /= 2;
    }
    return ans;
  }

 public:
  double myPow(double x, int n) { return myPowLL(x, n); }
};