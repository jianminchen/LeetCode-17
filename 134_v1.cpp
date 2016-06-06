/*
  134_v1.cpp
  Gas Station

  My first submission got WA because I've used an incorrect condition to check
  whether the car has actually traveled around the circuit. Instead of using
  "cnt == n", I've used "curr == idx" but this won't handle the case where the
  car just failed to pass the very first station "idx".
*/

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size(), sumGas = 0, sumCost = 0;
    for (int i = 0; i < n; i++) {
      sumGas += gas[i];
      sumCost += cost[i];
    }
    if (sumGas < sumCost) return -1;
    int idx = 0;
    while (true) {
      int amount = 0, curr = idx, cnt = 0;
      do {
        amount += gas[curr];
        amount -= cost[curr];
        if (amount < 0) break;
        curr = (curr + 1) % n;
        cnt++;
      } while (cnt < n);
      if (cnt == n)
        return idx;
      else
        idx = (curr + 1) % n;
    }
  }
};