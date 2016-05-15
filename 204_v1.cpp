/*
  204_v1.cpp
  Count Primes

  I didn't notice we are counting the number of primes numbers **less than** n
  and got my first WA.
*/

class Solution {
 public:
  int countPrimes(int n) {
    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    int cnt = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime[i]) {
        cnt++;
        for (int j = i + i; j <= n; j += i) isPrime[j] = false;
      }
    }
    return cnt;
  }
};