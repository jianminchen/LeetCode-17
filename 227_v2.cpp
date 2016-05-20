/*
  227_v2.cpp
  Basic Calculator II

  In 227_v1.cpp, the approach I've implemented uses two stacks: a number stack
  and an operator stack. At any time I always ensure the operators in the
  operator stack have a decreasing order of precedence when viewed from the top
  of the stack to the bottom. For instance, "1 + 2 * 3" will become one of the
  "final forms" of the expression since we can evaluate this expression in a way
  that is similar to RPN. We just need to continuously pop the operator, two
  numbers from the top of the stack and then push the new result into the number
  stack.

  Another example is "1 + 2 * 3 / 4", when we see "/", we know that "/" and "*"
  have the same level of precedence and so we can no longer keep such an
  expression in the stack since then when we evaluate the expression we would
  evaluate "3 / 4" first, which is incorrect. Therefore, when this happens we
  will evaluate "2 * 3" first and then convert the expression to "1 + 6 / ..."
  Notice that when we meet the '/' operator in the code we haven't seen '4' yet.
  But this way at least we still preserve a partial expression that can be
  evaluated easily later.

  Well, in this version (227_v2.cpp), things are becoming much simpler. Consider
  a complicated expression like this:

  1 + 2 - 3 * 4 / 5 + 6 - 7 * 8 / 9

  This expression essentially is equivalent to:

  1 + 2 - (12 / 5) + 6 - (56 / 9)
  1 + 2 - 2 + 6 - 6
  1 + 2 + (-2) + 6 + (-6)

  So essentially for any expression that contains +, -, * and / we can always
  reduce the original expression to an expression containing + and - character
  first. After this step we can again reduce the expression to a group of
  numbers and the value of the original expression is equal to the sum of these
  numbers. In the abovementioned example we have transformed the original
  expression to the final state: 1 + 2 + (-2) + 6 + (-6).

  Now the next question is how. For the simple case where we only have + and -
  operators, we can transform the expression into a list of numbers and then
  calculate the sum of these numbers. This can be done easily. When we extend
  from just + and - operators to * and /. If the previous sign is '*' or '/'
  after we have finished reading a new number, we can just pop the top number
  from the stack, either multiply or divide the new number and then push the
  number onto the stack. In this way we are always maintaining a list of
  integers and the final answer is simply the sum of all of these numbers.
*/

class Solution {
 public:
  int calculate(string s) {
    s += '+';
    char prevSign = '+';
    int currNum = 0;
    stack<int> numbers;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ')
        continue;
      else if (isdigit(s[i]))
        currNum = currNum * 10 + (s[i] - '0');
      else {
        if (prevSign == '+')
          numbers.push(currNum);
        else if (prevSign == '-')
          numbers.push(-currNum);
        else {
          int prevNum = numbers.top();
          numbers.pop();
          numbers.push(prevSign == '*' ? prevNum * currNum : prevNum / currNum);
        }
        currNum = 0;
        prevSign = s[i];
      }
    }
    int sumOfNumbers = 0;
    while (!numbers.empty()) {
      sumOfNumbers += numbers.top();
      numbers.pop();
    }
    return sumOfNumbers;
  }
};