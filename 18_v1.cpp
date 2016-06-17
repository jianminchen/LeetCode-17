/*
  18_v1.cpp
  4Sum

  The tricky part here is to de-dupe the quadruplets. My first submission got WA
  because of this and in my second submission I just used a "set<vector<int>>"
  to solve this problem. I understand this cannot be an ideal solution though.
*/

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ret;
    if (nums.size() == 0) return ret;

    sort(nums.begin(), nums.end());
    unordered_map<int, vector<pair<int, int>>> m;
    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        int sum = nums[i] + nums[j];
        m[sum].emplace_back(i, j);
      }
    }
    for (auto it : m) {
      int s1 = it.first;
      if (m.find(target - s1) == m.end()) continue;
      for (int i = 0; i < it.second.size(); i++) {
        auto p1 = it.second[i];
        for (int j = 0; j < m[target - s1].size(); j++) {
          auto p2 = m[target - s1][j];
          if (p1.second < p2.first) {
            vector<int> q{nums[p1.first], nums[p1.second], nums[p2.first],
                          nums[p2.second]};
            s.insert(q);
          }
        }
      }
    }

    for (auto v : s) {
      ret.push_back(v);
    }

    return ret;
  }
};