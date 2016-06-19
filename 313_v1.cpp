/*
  313_v1.cpp
  Super Ugly Number
*/

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> uglyNumbers;
    uglyNumbers.push_back(1);
    vector<int> ptrs;
    for (int i = 0; i < primes.size(); i++) ptrs.push_back(0);
    for (int i = 1; i < n; i++) {
      int minVal = uglyNumbers[ptrs[0]] * primes[0];
      for (int j = 1; j < primes.size(); j++)
        minVal = min(minVal, uglyNumbers[ptrs[j]] * primes[j]);
      uglyNumbers.push_back(minVal);
      for (int j = 0; j < primes.size(); j++)
        if (uglyNumbers[ptrs[j]] * primes[j] == minVal) ptrs[j]++;
    }
    return uglyNumbers[n - 1];
  }
};