/*
  66_v1.cpp
  Plus One
*/

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    reverse(digits.begin(), digits.end());
    int carry = 0;
    for (int i = 0; i < digits.size(); i++) {
      digits[i] = digits[i] + (i == 0 ? 1 : 0) + carry;
      carry = digits[i] / 10;
      digits[i] %= 10;
    }
    if (carry) digits.push_back(carry);
    reverse(digits.begin(), digits.end());
    return digits;
  }
};