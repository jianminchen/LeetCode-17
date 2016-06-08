/*
  60_v1.cpp
  Permutation Sequence
*/

class Solution {
 public:
  string getPermutation(int n, int k) {
    bool used[n + 1];
    memset(used, false, sizeof(used));
    k--;
    string ret = "";
    int factorial = 1;
    for (int i = 1; i <= n - 1; i++) factorial *= i;
    for (int i = 1; i <= n; i++) {
      int idx = k / factorial, cnt = 0;
      int val = -1;
      for (int j = 1; j <= n; j++) {
        if (!used[j]) {
          if (cnt == idx) {
            val = j;
            break;
          }
          cnt++;
        }
      }
      used[val] = true;
      ret += to_string(val);
      if (idx > 0) k -= idx * factorial;
      if (i != n) factorial /= (n - i);
    }
    return ret;
  }
};