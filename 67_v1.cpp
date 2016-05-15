/*
  67_v1.cpp
  Add Binary
*/

class Solution {
 public:
  string addBinary(string a, string b) {
    int p1 = a.size() - 1, p2 = b.size() - 1, carry = 0;
    string ret = "";
    while (p1 >= 0 || p2 >= 0) {
      int val1 = p1 >= 0 ? a[p1] - '0' : 0;
      int val2 = p2 >= 0 ? b[p2] - '0' : 0;
      int sum = val1 + val2 + carry;
      if (sum < 2)
        carry = 0;
      else
        sum -= 2, carry = 1;
      ret += (sum + '0');
      if (p1 >= 0) p1--;
      if (p2 >= 0) p2--;
    }
    if (carry) ret += (carry + '0');
    reverse(ret.begin(), ret.end());
    return ret;
  }
};