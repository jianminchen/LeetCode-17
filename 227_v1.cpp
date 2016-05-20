/*
  227_v1.cpp
  Basic Calculator II
*/

class Solution {
  int calcBinaryOperatorRet(char oper, int number1, int number2) {
    // cout << oper << " " << number1 << " " << number2 << endl;
    if (oper == '+')
      return number1 + number2;
    else if (oper == '-')
      return number1 - number2;
    else if (oper == '*')
      return number1 * number2;
    else
      return number1 / number2;
  }

 public:
  int calculate(string s) {
    map<char, int> operatorLevelMap = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    stack<int> numbers;
    stack<char> operators;
    int currentNum = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ')
        continue;
      else if (isdigit(s[i]))
        currentNum = currentNum * 10 + (s[i] - '0');
      else {
        numbers.push(currentNum);
        currentNum = 0;
        int currentOperatorLevel = operatorLevelMap[s[i]];
        while (!operators.empty() &&
               currentOperatorLevel <= operatorLevelMap[operators.top()]) {
          int topNumber1 = numbers.top();
          numbers.pop();
          int topNumber2 = numbers.top();
          numbers.pop();
          char topOperator = operators.top();
          numbers.push(
              calcBinaryOperatorRet(topOperator, topNumber2, topNumber1));
          operators.pop();
        }
        operators.push(s[i]);
      }
    }
    numbers.push(currentNum);

    while (!operators.empty()) {
      char topOperator = operators.top();
      operators.pop();
      int topNumber1 = numbers.top();
      numbers.pop();
      int topNumber2 = numbers.top();
      numbers.pop();
      numbers.push(calcBinaryOperatorRet(topOperator, topNumber2, topNumber1));
    }
    return numbers.top();
  }
};