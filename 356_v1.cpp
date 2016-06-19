/*
  356_v1.cpp
  Line Reflection

  My first submission got RTE because I didn't consider the case where
  points.size() == 0. Putting that submission aside my second and third
  submissions both made the same mistake since I didn't realize there can only
  be one valid value of "sum".

  In fact, after checking the posts, I've realized sum actually = minX + maxX so
  there is no need for me to do this sorting and two pointer manipulation at
  all. I'm really stupid...
*/

class PointComparer {
 public:
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
  }
};

class Solution {
 public:
  bool isReflected(vector<pair<int, int>>& points) {
    if (points.size() == 0) return true;
    sort(points.begin(), points.end(), PointComparer());
    int currY = points[0].second;
    int start = 0, end = 0, sum = 0;
    bool hasSum = false;
    for (int i = 1; i < points.size(); i++) {
      if (points[i].second == currY)
        end = i;
      else {
        if (!hasSum) {
          hasSum = true;
          sum = points[start].first + points[end].first;
        }
        while (start <= end) {
          if (points[start].first + points[end].first != sum) return false;
          start++;
          end--;
        }
        currY = points[i].second;
        start = i;
        end = i;
      }
    }
    if (!hasSum) {
      hasSum = true;
      sum = points[start].first + points[end].first;
    }
    while (start <= end) {
      if (points[start].first + points[end].first != sum) return false;
      start++;
      end--;
    }
    return true;
  }
};