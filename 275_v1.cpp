/*
  275_v1.cpp
  H-Index II
*/

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int lo = 0, hi = citations.size() - 1, mid, ret = 0;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      /*
      cout << lo << " " << hi << endl;
      cout << mid << " " << citations[mid] << " " << citations.size() - mid <<
      endl;
      */
      if (citations[mid] >= citations.size() - mid) {
        hi = mid - 1;
        ret = citations.size() - mid;
      } else {
        lo = mid + 1;
      }
    }
    return ret;
  }
};