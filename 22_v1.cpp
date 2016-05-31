/*
  22_v1.cpp
  Generate Parentheses
*/

class Solution {
  vector<string> ret;
  void dfs(string str, int currDepth, int n, int numLeftBrackets,
           int numOpenLeftBrackets) {
    if (currDepth == n * 2) ret.push_back(str);
    if (numLeftBrackets < n)
      dfs(str + "(", currDepth + 1, n, numLeftBrackets + 1,
          numOpenLeftBrackets + 1);
    if (numOpenLeftBrackets > 0)
      dfs(str + ")", currDepth + 1, n, numLeftBrackets,
          numOpenLeftBrackets - 1);
  }

 public:
  vector<string> generateParenthesis(int n) {
    ret.clear();
    dfs("(", 1, n, 1, 1);
    return ret;
  }
};