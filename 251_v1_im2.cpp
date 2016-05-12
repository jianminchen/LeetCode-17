/*
  251_v1_im2.cpp
  Flatten 2D Vector

  This version is even cleaner compared to 251_v1_im.cpp. We don't need to do
  any special handling in next() and we leave all the validity check in
  hasNext().
*/

class Vector2D {
 private:
  int r, c, numRows;
  vector<vector<int>> v;

 public:
  Vector2D(vector<vector<int>>& vec2d) {
    v = vec2d;
    r = 0;
    c = 0;
    numRows = v.size();
  }

  int next() {
    int val = v[r][c];
    c++;
    return val;
  }

  bool hasNext() {
    if (numRows == 0) return false;
    while (r < numRows && c == v[r].size()) r++, c = 0;
    return r < numRows;
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */