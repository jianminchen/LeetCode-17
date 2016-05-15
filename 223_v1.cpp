/*
  223_v1.cpp
  Rectangle Area

  My first two submission got WA because I didn't handle the "no overlap" case
  correctly. In fact this version is not the version which I first got AC. I've
  complicated the problem and tried to check whether (A, B, C, D) is inside (E,
  F, G, H) or vice versa. This is totally not necessary as this will still be
  covered by the generic overlap case.
*/

class Solution {
  int rectArea(int x1, int y1, int x2, int y2) { return (x2 - x1) * (y2 - y1); }

 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if (C <= E || D <= F || G <= A || H <= B)
      return rectArea(E, F, G, H) + rectArea(A, B, C, D);
    vector<int> x{A, C, E, G};
    sort(x.begin(), x.end());
    vector<int> y{B, D, F, H};
    sort(y.begin(), y.end());
    return rectArea(A, B, C, D) + rectArea(E, F, G, H) -
           rectArea(x[1], y[1], x[2], y[2]);
  }
};