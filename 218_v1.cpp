/*
  218_v1.cpp
  The Skyline Problem

  My first submission got WA because I didn't consider a very special case:
  [[1,2,1],[1,2,2],[1,2,3]].

  This test case means at a particular x-coordinate x_0, multiple buildings are
  "entering" the sweepline, if we directly output the maximum value stored in
  the BST after each event, it will return [1, 1], [1, 2] and [1, 3].
*/

class Solution {
 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<pair<int, int>, int>> heights;
    for (int i = 0; i < buildings.size(); i++) {
      int l = buildings[i][0], r = buildings[i][1], h = buildings[i][2];
      auto p1 = make_pair(l, h);
      heights.emplace_back(p1, -1);
      auto p2 = make_pair(r, h);
      heights.emplace_back(p2, 1);
    }
    sort(heights.begin(), heights.end());
    map<int, int> m;
    int prevHeight = -1;
    vector<pair<int, int>> ret;
    for (int i = 0; i < heights.size(); i++) {
      bool insert = (heights[i].second == -1);
      int x = heights[i].first.first, h = heights[i].first.second;
      if (insert)
        m[h]++;
      else
        m[h]--;

      if (m[h] == 0) {
        auto tmpIt = m.find(h);
        m.erase(tmpIt);
      }

      if (m.empty()) {
        ret.emplace_back(x, 0);
        prevHeight = 0;
      } else {
        auto it = m.rbegin();
        if (it->first != prevHeight) {
          if (ret.empty() || ret.back().first != x)
            ret.emplace_back(x, it->first);
          else {
            ret[ret.size() - 1] = make_pair(x, it->first);
          }
          prevHeight = it->first;
        }
      }
    }
    return ret;
  }
};