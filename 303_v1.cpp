/*
  303_v1.cpp
  Range Sum Query - Immutable

  I've made a typo in my first submission.
*/

class NumArray {
  vector<int> sum;

 public:
  NumArray(vector<int> &nums) {
    sum.resize(nums.size() + 1);
    fill(sum.begin(), sum.end(), 0);
    sum[0] = 0;
    for (int i = 1; i <= nums.size(); i++) sum[i] += sum[i - 1] + nums[i - 1];
  }

  int sumRange(int i, int j) { return sum[j + 1] - sum[i]; }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);