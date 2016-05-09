/*
  1_v1.cpp
  Two Sum

  My first submission got WA because I forgot to add "if (it.second.size() >=
  2)".
*/

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < nums.size(); i++) m[nums[i]].push_back(i);
    vector<int> ret;
    for (auto it : m) {
      int val = it.first;
      if (target - val != val) {
        if (m.find(target - val) != m.end()) {
          ret = vector<int>{(it.second)[0], m[target - val][0]};
          return ret;
        }
      } else {
        if (it.second.size() >= 2) {
          ret.push_back((it.second)[0]);
          ret.push_back((it.second)[1]);
          return ret;
        }
      }
    }
    return ret;
  }
};