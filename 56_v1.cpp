/*
  56_v1.cpp
  Merge Intervals
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
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ret;
    if (intervals.size() == 0) return ret;

    vector<pair<int, int>> timestamps;
    for (int i = 0; i < intervals.size(); i++) {
      timestamps.emplace_back(intervals[i].start, -1);
      timestamps.emplace_back(intervals[i].end, 1);
    }
    sort(timestamps.begin(), timestamps.end());

    int cnt = 0, prevtime;
    for (int i = 0; i < timestamps.size(); i++) {
      if (cnt == 0) prevtime = timestamps[i].first;
      cnt += timestamps[i].second;
      if (cnt == 0) ret.push_back(Interval(prevtime, timestamps[i].first));
    }
    return ret;
  }
};