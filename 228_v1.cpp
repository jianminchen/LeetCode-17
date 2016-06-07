/*
  228_v1.cpp
  Summary Ranges
*/

class Solution {
 private:
  string convertToRange(int rangeStart, int rangeEnd) {
    if (rangeStart == rangeEnd)
      return to_string(rangeStart);
    else
      return to_string(rangeStart) + "->" + to_string(rangeEnd);
  }

 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    int n = nums.size();
    if (n == 0) return ret;
    int rangeStart = nums[0], rangeEnd = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] == rangeEnd + 1)
        rangeEnd = nums[i];
      else {
        ret.push_back(convertToRange(rangeStart, rangeEnd));
        rangeStart = nums[i], rangeEnd = nums[i];
      }
    }
    ret.push_back(convertToRange(rangeStart, rangeEnd));
    return ret;
  }
};