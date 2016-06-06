/*
  17_v1.cpp
  Letter Combinations of a Phone Number

  Got WA in my first submission since I didn't handle invalid input.
*/

class Solution {
 private:
  map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                         {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                         {'8', "tuv"}, {'9', "wxyz"}};
  vector<string> ret;
  void dfs(string digits, int depth, string letter) {
    if (depth == digits.size()) {
      ret.push_back(letter);
      return;
    }
    char ch = digits[depth];
    for (int i = 0; i < m[ch].size(); i++)
      dfs(digits, depth + 1, letter + m[ch][i]);
  }

 public:
  vector<string> letterCombinations(string digits) {
    ret.clear();
    if (digits == "") return ret;
    if (digits.find('0') != string::npos) return ret;
    if (digits.find('1') != string::npos) return ret;
    dfs(digits, 0, "");
    return ret;
  }
};