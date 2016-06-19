/*
  315_v1.cpp
  Count of Smaller Numbers After Self

  My first submission had some off-by-one bugs in handling n and cnt and got
  RTE.
*/

class Solution {
 private:
  vector<int> bit;
  int n;

  int sum(int i) {
    int ret = 0;
    while (i) {
      ret += bit[i];
      i -= i & -i;
    }
    return ret;
  }

  void add(int i, int val) {
    while (i <= n) {
      bit[i] += val;
      i += i & -i;
    }
  }

 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> ret;
    if (nums.size() == 0) return ret;
    vector<int> tmp(nums);
    sort(tmp.begin(), tmp.end());
    unordered_map<int, int> hash;
    hash[tmp[0]] = 1;
    int prev = tmp[0], cnt = 2;
    for (int i = 1; i < tmp.size(); i++) {
      if (tmp[i] != prev) {
        hash[tmp[i]] = cnt++;
        prev = tmp[i];
      }
    }
    if (tmp.back() != prev) hash[tmp.back()] = cnt++;
    bit.resize(cnt);
    fill(bit.begin(), bit.end(), 0);
    n = cnt - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      int hashVal = hash[nums[i]];
      ret.push_back(sum(hashVal - 1));
      add(hashVal, 1);
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};