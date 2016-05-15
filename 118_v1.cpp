/*
  118_v1.cpp
  Pascal's Triangle
*/

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret;
    if (numRows == 0) return ret;
    vector<int> v{1};
    ret.push_back(v);
    for (int i = 2; i <= numRows; i++) {
      vector<int> lastRow = ret.back();
      v.clear();
      v.push_back(1);
      for (int j = 0; j + 1 < lastRow.size(); j++)
        v.push_back(lastRow[j] + lastRow[j + 1]);
      v.push_back(1);
      ret.push_back(v);
    }
    return ret;
  }
};