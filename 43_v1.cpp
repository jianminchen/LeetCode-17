/*
  43_v1.cpp
  Multiply Strings

  My first submission got WA since I forgot to handle leading zeros for test
  cases like "9133" and "0". My initial submission would return "0000".
*/

class Solution {
 public:
  string multiply(string num1, string num2) {
    vector<int> result;
    result.resize(num1.size() + num2.size() - 1);
    fill(result.begin(), result.end(), 0);
    for (int i = 0; i < num1.size(); i++) {
      for (int j = 0; j < num2.size(); j++) {
        int num1Idx = num1.size() - i - 1;
        int num2Idx = num2.size() - j - 1;
        result[num1Idx + num2Idx] += (num1[i] - '0') * (num2[j] - '0');
      }
    }
    int carry = 0;
    for (int i = 0; i < result.size(); i++) {
      int tmp = carry;
      carry = (result[i] + carry) / 10;
      result[i] = (result[i] + tmp) % 10;
    }
    while (carry) {
      result.push_back(carry % 10);
      carry /= 10;
    }
    while (result.back() == 0 && result.size() > 1) result.pop_back();
    string resultStr = "";
    for (int i = result.size() - 1; i >= 0; i--) resultStr += (result[i] + '0');
    return resultStr;
  }
};