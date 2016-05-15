/*
  119_v1.cpp
  Pascal's Triangle II
*/

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> prevRow, currRow;
    prevRow.push_back(1);
    if (rowIndex == 0) return prevRow;
    for (int i = 1; i <= rowIndex; i++) {
      currRow.clear();
      currRow.push_back(1);
      for (int j = 0; j + 1 < prevRow.size(); j++)
        currRow.push_back(prevRow[j] + prevRow[j + 1]);
      currRow.push_back(1);
      prevRow = currRow;
    }
    return prevRow;
  }
};