/*
  135_v1.cpp
  Candy

  My first two submission failed because I didn't read the problem carefully:
  Children with a **higher** rating get more candies than their neighbors so I
  need to handle the tie cases more carefully.
*/

class Solution {
 public:
  int candy(vector<int>& ratings) {
    if (ratings.size() == 0) return 0;
    int assigned[ratings.size()];
    memset(assigned, 0, sizeof(assigned));
    vector<pair<int, int>> v;
    for (int i = 0; i < ratings.size(); i++)
      v.push_back(make_pair(ratings[i], i));
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
      int idx = v[i].second;
      int val1 = 1, val2 = 1;
      bool flag = false;
      if (idx > 0 && assigned[idx - 1] != 0 && v[i].first > ratings[idx - 1])
        val1 = assigned[idx - 1] + 1;
      if (idx < ratings.size() - 1 && assigned[idx + 1] != 0 &&
          v[i].first > ratings[idx + 1])
        val2 = assigned[idx + 1] + 1;
      int toAssign = max(val1, val2);
      assigned[idx] = toAssign;
      ans += toAssign;
    }
    return ans;
  }
};