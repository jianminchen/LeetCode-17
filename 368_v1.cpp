/*
  368_v1.cpp
  Largest Divisible Subset

  My first submission got WA. I didn't think too much about the initialization
  part so I just went ahead and memset the two arrays f and prev as 0. This
  apparently is incorrect since f[] at least can be 1.
*/

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> ret;
    int n = nums.size(), f[n], prev[n];
    if (n == 0) return ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) f[i] = 1, prev[i] = i;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          if (f[j] + 1 > f[i]) {
            f[i] = f[j] + 1;
            prev[i] = j;
          }
        }
      }
    }
    int maxAns = 1, maxIdx = 0;
    for (int i = 1; i < n; i++) {
      if (f[i] > maxAns) {
        maxAns = f[i];
        maxIdx = i;
      }
    }
    ret.push_back(nums[maxIdx]);
    int currIdx = maxIdx;
    while (currIdx != prev[currIdx]) {
      currIdx = prev[currIdx];
      ret.push_back(nums[currIdx]);
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
};