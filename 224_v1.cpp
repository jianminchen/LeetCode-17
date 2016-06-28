/*
  224_v1.cpp
  Basic Calculator
*/

class Solution {
 private:
  unordered_map<char, int> operatorPrecedenceMap{{'+', 1}, {'-', 1}, {'*', 2},
                                                 {'/', 2}, {'(', 0}, {')', 0}};

  vector<string> infix_to_postfix(string s) {
    vector<string> ret;
    stack<char> op;
    int currVal = 0;
    bool hasVal = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') continue;
      if (isdigit(s[i])) {
        currVal = currVal * 10 + (s[i] - '0');
        hasVal = true;
      } else {
        if (hasVal) {
          ret.push_back(to_string(currVal));
          hasVal = false;
        }
        currVal = 0;

        if (s[i] == '(')
          op.push(s[i]);
        else if (s[i] == ')') {
          while (op.top() != '(') {
            ret.push_back(string(1, op.top()));
            op.pop();
          }
          op.pop();
        } else {
          int currPrecedence = operatorPrecedenceMap[s[i]];
          while (!op.empty() &&
                 currPrecedence <= operatorPrecedenceMap[op.top()]) {
            ret.push_back(string(1, op.top()));
            op.pop();
          }
          op.push(s[i]);
        }
      }
    }
    if (hasVal) {
      ret.push_back(to_string(currVal));
      hasVal = true;
    }
    while (!op.empty()) {
      ret.push_back(string(1, op.top()));
      op.pop();
    }
    return ret;
  }

  int eval(vector<string>& postfix) {
    stack<int> vals;
    for (string str : postfix) {
      if (str.size() == 1 && (!isdigit(str[0]))) {
        int val2 = vals.top();
        vals.pop();
        int val1 = vals.top();
        vals.pop();
        switch (str[0]) {
          case '+':
            vals.push(val1 + val2);
            break;
          case '-':
            vals.push(val1 - val2);
            break;
          case '*':
            vals.push(val1 * val2);
            break;
          case '/':
            vals.push(val1 / val2);
            break;
        }
      } else {
        vals.push(stoi(str));
      }
    }
    return vals.top();
  }

 public:
  int calculate(string s) {
    vector<string> postfix = infix_to_postfix(s);
    return eval(postfix);
  }
};