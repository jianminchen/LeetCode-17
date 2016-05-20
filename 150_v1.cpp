/*
  150_v1.cpp
  Evaluate Reverse Polish Notation

  My first submission got WA since I was trying to using "isdigit(tokens[i][0])"
  to check whether tokens[i] is a number or not. This logic misses all negative
  numbers.
*/

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> numbers;
    for (int i = 0; i < tokens.size(); i++) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
          tokens[i] == "/") {
        int topNumber1 = numbers.top();
        numbers.pop();
        int topNumber2 = numbers.top();
        numbers.pop();
        if (tokens[i] == "+")
          numbers.push(topNumber2 + topNumber1);
        else if (tokens[i] == "-")
          numbers.push(topNumber2 - topNumber1);
        else if (tokens[i] == "*")
          numbers.push(topNumber2 * topNumber1);
        else
          numbers.push(topNumber2 / topNumber1);
      } else
        numbers.push(stoi(tokens[i]));
    }
    return numbers.top();
  }
};