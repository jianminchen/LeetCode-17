/*
  307_v2.cpp
  Range Sum Query - Mutable
*/

class NumArray {
 private:
  int n;
  vector<int> bits, nums;

  void add(int i, int val) {
    while (i <= n) {
      bits[i] += val;
      i += i & -i;
    }
  }

  int sum(int i) {
    int ret = 0;
    while (i) {
      ret += bits[i];
      i -= i & -i;
    }
    return ret;
  }

 public:
  NumArray(vector<int> &nums) {
    this->nums = nums;
    n = nums.size();
    bits.resize(n + 1);
    for (int i = 1; i <= n; i++) add(i, nums[i - 1]);
  }

  void update(int i, int val) {
    int diff = val - nums[i];
    nums[i] = val;
    add(i + 1, diff);
  }

  int sumRange(int i, int j) { return sum(j + 1) - sum(i); }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);