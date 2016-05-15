/*
  281_v1.cpp
  Zigzag Iterator
*/

class ZigzagIterator {
  int vectorIdx, itemIdx;
  vector<vector<int>> v;

 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    v.push_back(v1);
    v.push_back(v2);
    vectorIdx = 0;
    itemIdx = 0;
  }

  int next() {
    hasNext();
    int val = v[vectorIdx][itemIdx];
    if (vectorIdx == v.size() - 1) {
      vectorIdx = 0;
      itemIdx++;
    } else {
      vectorIdx++;
    }
    return val;
  }

  bool hasNext() {
    int cnt = 0;
    while (itemIdx >= v[vectorIdx].size() && cnt < v.size()) {
      cnt++;
      if (vectorIdx == v.size() - 1) {
        vectorIdx = 0;
        itemIdx++;
      } else {
        vectorIdx++;
      }
    }
    if (cnt == v.size()) return false;
    return true;
  }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */