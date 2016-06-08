/*
  149_v1.cpp
  Max Points on a Line

  My first submission didn't handle the empty input case and the second
  submission didn't handle the case where there can have multiple points which
  have same coordinates.
*/

/**
*Definition for a point.
*struct Point {
*    int x;
*    int y;
*    Point() : x(0), y(0) {}
*    Point(int a, int b) : x(a), y(b) {}
*};
*/
class Solution {
 private:
  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

 public:
  int maxPoints(vector<Point>& points) {
    int n = points.size();
    if (n == 0) return 0;
    int ans = 0;
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++) {
      m.clear();
      int commonx = 0, same = 0;
      for (int j = 0; j < n; j++) {
        int dx = points[i].x - points[j].x;
        int dy = points[i].y - points[j].y;
        if (dx == 0 && dy == 0) {
          same++;
          continue;
        }
        if (dx == 0) {
          commonx++;
          continue;
        }

        int g = gcd(dx, dy);
        dx /= g;
        dy /= g;
        m[make_pair(dx, dy)]++;
      }
      ans = max(ans, commonx + same);
      for (auto it : m) ans = max(ans, it.second + same);
    }
    return ans;
  }
};