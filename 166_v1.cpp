/*
  166_v1.cpp
  Fraction to Recurring Decimal

  Wow!

  There are indeed a bunch of edge cases.

  My first submission failed on -2147483648, -1.
  My second submission failed on 1, 6.
  My third submission failed on -50, 8.
  My fourth submission failed on 7, -12.
  My fifth submission failed on 1, 5, due to a pair of missing brackets for
  (numerator ^ denominator).
  My sixth submission failed on 0, -5. (This is really tricky since my output
  was -0.)
  My seventh submission failed on -1, -2147483648 (need to use long long).
*/

class Solution {
 public:
  string fractionToDecimal(int _numerator, int _denominator) {
    unordered_map<int, int> m;
    long long numerator = _numerator;
    long long denominator = _denominator;
    bool negative = false;
    if ((numerator ^ denominator) < 0) negative = true;
    numerator = abs(numerator), denominator = abs(denominator);
    string firstPart = to_string(numerator / denominator);
    numerator %= denominator;

    string ans = "";
    if (negative) ans += '-';

    if (numerator == 0) {
      ans += firstPart;
      if (ans == "-0") return "0";
      return ans;
    } else {
      if (numerator < 0) numerator = -numerator;
      vector<int> secondPart;
      long long rem = numerator;
      m[rem] = 0;
      while (rem != 0) {
        rem *= 10;
        long long tmp = rem / denominator;
        secondPart.push_back(tmp);
        rem %= denominator;
        if (m.find(rem) != m.end())
          break;
        else {
          m[rem] = secondPart.size();
        }
      }
      ans += firstPart + ".";
      for (int i = 0; i < secondPart.size(); i++) {
        if (i == m[rem] && rem != 0) ans += '(';
        ans += secondPart[i] + '0';
      }
      if (rem) ans += ')';
      return ans;
    }
  }
};