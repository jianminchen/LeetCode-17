/*
  169_v1.cpp
  Majority Element
*/

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int ans = nums[0], cnt = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == ans)
        cnt++;
      else
        cnt--;
      if (cnt == 0) ans = nums[i], cnt = 1;
    }
    return ans;
  }
};