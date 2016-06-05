/*
  229_v1.cpp
  Majority Element II

  I got WA in my first submission because I didn't think of it clearly. In the
  for loop, the five conditions actually have precedences. We need to always
  check whether nums[i] == val1 / val2 first instead of check whether cnt1 or
  cnt2 == 0 first since then we may end up having the same value for val1 and
  val2.
*/

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int val1, cnt1 = 0, val2, cnt2 = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      if (cnt1 && nums[i] == val1)
        cnt1++;
      else if (cnt2 && nums[i] == val2)
        cnt2++;
      else if (cnt1 == 0)
        val1 = nums[i], cnt1++;
      else if (cnt2 == 0)
        val2 = nums[i], cnt2++;
      else {
        cnt1--;
        cnt2--;
      }
      // cout << val1 << " " << cnt1 << " " << val2 << " " << cnt2 << endl;
    }
    vector<int> ret;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == val1)
        cnt1++;
      else if (nums[i] == val2)
        cnt2++;
    }
    if (cnt1 > n / 3) ret.push_back(val1);
    if (cnt2 > n / 3) ret.push_back(val2);
    return ret;
  }
};