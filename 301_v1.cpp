/*
  301_v1.cpp
  Remove Invalid Parentheses
*/

class Solution {
 private:
  int minDeletion;

  void search(int pos, string s, string curr, int numDeletion,
              int numOpenLeftBracket, unordered_set<string>& ret) {
    if (numDeletion > minDeletion) return;

    if (pos == s.size()) {
      if (numOpenLeftBracket == 0) ret.insert(curr);
      return;
    }

    if (s[pos] != '(' && s[pos] != ')')
      search(pos + 1, s, curr + s[pos], numDeletion, numOpenLeftBracket, ret);

    else if (s[pos] == ')') {
      search(pos + 1, s, curr, numDeletion + 1, numOpenLeftBracket, ret);
      if (numOpenLeftBracket > 0)
        search(pos + 1, s, curr + s[pos], numDeletion, numOpenLeftBracket - 1,
               ret);
    }

    else {
      search(pos + 1, s, curr, numDeletion + 1, numOpenLeftBracket, ret);
      search(pos + 1, s, curr + s[pos], numDeletion, numOpenLeftBracket + 1,
             ret);
    }
  }

 public:
  vector<string> removeInvalidParentheses(string s) {
    minDeletion = 0;
    int numOpenLeftBracket = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        numOpenLeftBracket++;
      else if (s[i] == ')') {
        if (numOpenLeftBracket == 0)
          minDeletion++;
        else
          numOpenLeftBracket--;
      }
    }
    minDeletion += numOpenLeftBracket;
    unordered_set<string> ret;
    string curr = "";
    search(0, s, curr, 0, 0, ret);
    return vector<string>(ret.begin(), ret.end());
  }
};