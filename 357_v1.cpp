/*
  357_v1.cpp
  Count Numbers with Unique Digits
*/

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;

    int f[11] = {0};
    f[1] = 10;
    int ans = 10;
    for (int i = 2; i <= n; i++) {
      int tot = 1, curr = 10;
      for (int j = 1; j <= i; j++) {
        if (j == 1)
          tot *= (curr - 1);
        else
          tot *= curr;
        curr--;
      }
      f[i] = tot;
      cout << tot << endl;
      ans += tot;
    }
    return ans;
  }
};