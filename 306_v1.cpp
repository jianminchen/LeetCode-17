/*
  306_v1.cpp
  Additive Number

  My first two submissions got WA because I haven't handled the "leading zeros"
  cases. In fact in my second submission I've even handled it in an incorrect
  way. I've directly checked if (a[0] == '0' || b[0] == '0') in the test()
  function. This is incorrect since the value for a or b itself may be 0.
*/

class Solution {
 private:
  string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ret = "";
    int carry = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
      int val1 = i < a.size() ? a[i] - '0' : 0;
      int val2 = i < b.size() ? b[i] - '0' : 0;
      int sum = (val1 + val2 + carry);
      ret += sum % 10 + '0';
      carry = sum / 10;
    }
    if (carry) {
      ret += carry + '0';
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
  bool test(int idx, string a, string b, string num) {
    if (idx == num.size()) return true;
    if (a[0] == '0' && a.size() > 1) return false;
    if (b[0] == '0' && b.size() > 1) return false;
    string sum = add(a, b);
    // cout << idx << " " << a << " " << b << " " << sum << endl;
    for (int i = idx; i < idx + sum.size(); i++) {
      if (i >= num.size() || num[i] != sum[i - idx]) return false;
    }
    return test(idx + sum.size(), b, sum, num);
  }

 public:
  bool isAdditiveNumber(string num) {
    if (num.size() == 0) return false;
    int n = num.size();
    for (int i = 0; i <= n - 3; i++) {
      for (int j = i + 1; j <= n - 2; j++) {
        string a = num.substr(0, i + 1);
        string b = num.substr(i + 1, j - i);
        // cout << j + 1 << " " << a << " " << b << endl;
        if (test(j + 1, a, b, num)) return true;
      }
    }
    return false;
  }
};