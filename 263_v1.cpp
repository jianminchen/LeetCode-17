/*
  263_v1.cpp
  Ugly Number

  My first submission received WA because I didn't handle the special case where
  num == 0.
*/

class Solution {
 public:
  bool isUgly(int num) {
    if (num == 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
  }
};