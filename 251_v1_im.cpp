/*
  251_v1_im.cpp
  Flatten 2D Vector

  When we call next(), we return the current val in v[r][c] and hasNext() will
  guarantee v[r][c] is valid. Then we will try to increment (r, c) in next() but
  it may not be a valid pair, so we handle this in hasNext().
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
    if (c == v[r].size()) {
      r++;
      c = 0;
    }
    return val;
  }

  bool hasNext() {
    if (numRows == 0) return false;
    while (r < numRows && c == v[r].size()) r++;
    return r < numRows;
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */