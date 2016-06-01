/*
  57_v1.cpp
  Insert Interval
*/

/**
*Definition for an interval.
*struct Interval {
*    int start;
*    int end;
*    Interval() : start(0), end(0) {}
*    Interval(int s, int e) : start(s), end(e) {}
*};
*/
class Solution {
 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<pair<int, int>> v;
    intervals.push_back(newInterval);
    for (int i = 0; i < intervals.size(); i++) {
      v.push_back(make_pair(intervals[i].start, -1));
      v.push_back(make_pair(intervals[i].end, 1));
    }
    sort(v.begin(), v.end());
    vector<Interval> ret;
    int cnt = 0;
    int prevIntervalStart;
    for (int i = 0; i < v.size(); i++) {
      if (cnt == 0) prevIntervalStart = v[i].first;
      cnt += v[i].second;
      if (cnt == 0) ret.push_back(Interval(prevIntervalStart, v[i].first));
    }
    return ret;
  }
};