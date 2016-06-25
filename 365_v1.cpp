/*
  365_v1.cpp
  Water and Jug Problem

  My first submission got RTE because I didn't consider the case where z == 0.
  My second submission again got WA because I didn't consider the case where z
  <= x + y.
*/

class Solution {
 private:
  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

 public:
  bool canMeasureWater(int x, int y, int z) {
    if (z == 0) return true;
    int g = gcd(x, y);
    if (g == 0) return false;
    return z <= x + y && z % g == 0;
  }
};