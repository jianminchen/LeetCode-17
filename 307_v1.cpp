/*
  307_v1.cpp
  Range Sum Query - Mutable
*/

class NumArray {
 private:
  int n;
  vector<int> bit, nums;

  int sum(int i) {
    int s = 0;
    i++;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, int x) {
    i++;
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
  }

 public:
  NumArray(vector<int> &nums) {
    this->nums = nums;
    n = nums.size();
    bit.resize(n + 1);
    for (int i = 0; i < n; i++) add(i, nums[i]);
  }

  void update(int i, int val) {
    int diff = val - nums[i];
    nums[i] = val;
    add(i, diff);
  }

  int sumRange(int i, int j) { return sum(j) - sum(i - 1); }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);