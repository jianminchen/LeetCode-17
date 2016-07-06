/*
  370_v1.cpp
  Range Addition
*/

class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> ret(length, 0);
    for (int i = 0; i < updates.size(); i++) {
      int startIndex = updates[i][0];
      int endIndex = updates[i][1];
      int inc = updates[i][2];
      ret[startIndex] += inc;
      if (endIndex + 1 < length) ret[endIndex + 1] -= inc;
    }
    int sum = 0;
    for (int i = 0; i < ret.size(); i++) {
      sum += ret[i];
      ret[i] = sum;
    }
    return ret;
  }
};