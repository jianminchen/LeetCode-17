/*
  302_v1.cpp
  Smallest Rectangle Enclosing Black Pixels
*/

class Solution {
 public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    int nRow = image.size(), nCol = nRow ? image[0].size() : 0;
    int minX, maxX, minY, maxY;

    int lo = 0, hi = x, mid;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      bool found = false;
      for (int i = 0; i < nCol; i++) {
        if (image[mid][i] == '1') {
          found = true;
          break;
        }
      }
      if (found) {
        minX = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }

    lo = x, hi = nRow - 1;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      bool found = false;
      for (int i = 0; i < nCol; i++) {
        if (image[mid][i] == '1') {
          found = true;
          break;
        }
      }
      if (found) {
        maxX = mid;
        lo = mid + 1;
      } else
        hi = mid - 1;
    }

    lo = 0, hi = y;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      bool found = false;
      for (int i = 0; i < nRow; i++) {
        if (image[i][mid] == '1') {
          found = true;
          break;
        }
      }
      if (found) {
        minY = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }

    lo = y, hi = nCol - 1;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      bool found = false;
      for (int i = 0; i < nRow; i++) {
        if (image[i][mid] == '1') {
          found = true;
          break;
        }
      }
      if (found) {
        maxY = mid;
        lo = mid + 1;
      } else
        hi = mid - 1;
    }

    cout << minX << " " << maxX << endl;
    cout << minY << " " << maxY << endl;
    return (maxY - minY + 1) * (maxX - minX + 1);
  }
};