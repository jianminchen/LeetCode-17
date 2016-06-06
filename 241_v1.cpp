/*
  241_v1.cpp
  Different Ways to Add Parentheses
*/

class Solution {
 private:
  unordered_map<string, vector<int>> cache;

  vector<int> solve(string input) {
    if (cache.find(input) != cache.end()) return cache[input];

    vector<int> res;
    int num = 0;
    bool allNum = true;
    for (int i = 0; i < input.size(); i++) {
      if (!isdigit(input[i])) {
        allNum = false;
        string s1 = input.substr(0, i);
        string s2 = input.substr(i + 1, input.size() - i - 1);
        vector<int> v1 = diffWaysToCompute(s1);
        vector<int> v2 = diffWaysToCompute(s2);
        for (int val1 : v1) {
          for (int val2 : v2) {
            if (input[i] == '+')
              res.push_back(val1 + val2);
            else if (input[i] == '-')
              res.push_back(val1 - val2);
            else if (input[i] == '*')
              res.push_back(val1 * val2);
            else
              res.push_back(val1 / val2);
          }
        }
      } else {
        num = num * 10 + input[i] - '0';
      }
    }
    if (allNum)
      return cache[input] = vector<int>{num};
    else
      return cache[input] = res;
  }

 public:
  vector<int> diffWaysToCompute(string input) {
    cache.clear();
    return solve(input);
  }
};