/*
  233_v1.cpp
  Number of Digit One
*/

class Solution {
 public:
  int countDigitOne(int n) {
    if (n <= 0) return 0;
    if (n < 10) return 1;
    int lastDigit = n % 10;
    int val1 = countDigitOne(n / 10), val2 = countDigitOne(n / 10 - 1);
    int sum = val1 * (lastDigit + 1) + val2 * (9 - lastDigit);
    if (lastDigit >= 1)
      sum += n / 10 + 1;
    else
      sum += n / 10;
    return sum;
  }
};