/*
  251_v1.cpp
  Flatten 2D Vector
*/

class Vector2D {
 private:
  int i, j, r;
  vector<vector<int>> v;
  bool testNext(int ci, int cj, int& ni, int& nj) {
    ni = ci, nj = cj;
    if (ni >= 0 && nj < v[ci].size() - 1) {
      nj++;
      return true;
    } else {
      ni++;
      nj = 0;
      while (ni < r && v[ni].size() == 0) ni++;
      return ni < r;
    }
  }

 public:
  Vector2D(vector<vector<int>>& vec2d) {
    i = j = -1;
    v = vec2d;
    r = vec2d.size();
  }

  int next() {
    int ni, nj;
    testNext(i, j, ni, nj);
    i = ni, j = nj;
    return v[ni][nj];
  }

  bool hasNext() {
    int ni, nj;
    return testNext(i, j, ni, nj);
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */