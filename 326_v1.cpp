/*
  326_v1.cpp
  Power of Three

  I really haven't thought of this idea when I first tried to solve this problem
  as I was focusing more on whether I can find any interesting feature from the
  bit representation. Besides I didn't think of a way to calculate the maxVal.

  Again I was retarded to write something like "n == 0 || maxVal % n == 0" in my
  first submission. My second submission got WA again since I didn't consider
  negative cases.
*/

class Solution {
 public:
  bool isPowerOfThree(int n) {
    int maxVal = (int)pow(3, (int)(log(2147483647) / log(3)));
    return n > 0 && maxVal % n == 0;
  }
};