/*
  45_v1.cpp
  Jump Game II

  There was a simple mistake in my first submission as I've written something
  like "if (nums[i] > maxDist[currSteps]) currSteps++;". The key observation
  here is that maxDist is a non-decreasing sequence.
*/

class Solution {
 public:
  int jump(vector<int>& nums) {
    vector<int> maxDist;
    maxDist.push_back(0);

    int currSteps = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > maxDist[currSteps]) currSteps++;

      if (maxDist.size() - 1 < currSteps + 1) {
        maxDist.push_back(nums[i] + i);
        continue;
      }

      if (maxDist[currSteps + 1] < nums[i] + i)
        maxDist[currSteps + 1] = nums[i] + i;
    }

    for (int i = 0; i < maxDist.size(); i++) {
      // cout << maxDist[i] << " ";
      if (maxDist[i] >= nums.size() - 1) return i;
    }
    return -1;
  }
};