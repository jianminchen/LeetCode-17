/*
  274_v1.cpp
  H-Index
*/

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int ret = 0;
    for (int i = 0; i < citations.size(); i++) {
      if (citations[i] >= i + 1) ret = i + 1;
    }
    return ret;
  }
};