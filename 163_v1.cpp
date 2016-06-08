/*
  163_v1.cpp
  Missing Ranges
*/

class Solution {
 private:
  string createRange(int l, int u) {
    if (l == u)
      return to_string(l);
    else
      return to_string(l) + "->" + to_string(u);
  }

 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ret;
    if (nums.size() == 0) {
      ret.push_back(createRange(lower, upper));
      return ret;
    }
    if (nums[0] != lower) ret.push_back(createRange(lower, nums[0] - 1));
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1] + 1)
        ret.push_back(createRange(nums[i - 1] + 1, nums[i] - 1));
    }
    if (nums[nums.size() - 1] != upper)
      ret.push_back(createRange(nums[nums.size() - 1] + 1, upper));
    return ret;
  }
};