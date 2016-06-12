/*
  56_v2.cpp
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
    if (intervals.size() == 0) return vector<Interval>();
    vector<Interval> ret;
    sort(intervals.begin(), intervals.end(),
         [](Interval& a, Interval& b) { return a.start < b.start; });
    ret.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (ret.back().end < intervals[i].start)
        ret.push_back(intervals[i]);
      else
        ret.back().end = max(ret.back().end, intervals[i].end);
    }
    return ret;
  }
};