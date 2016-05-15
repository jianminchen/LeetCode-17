/*
  9_v1.cpp
  Palindrome Number

  A negative number is not a palindrome number. I thought -1234321 should be a
  palindrome number as well - so I got my first WA.
*/

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int reversedNum = 0, originalNum = x;
    while (x) {
      reversedNum = reversedNum * 10 + x % 10;
      x /= 10;
    }
    return reversedNum == originalNum;
  }
};