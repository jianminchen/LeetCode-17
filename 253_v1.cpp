/*
  253_v1.cpp
  Meeting Rooms II
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
  int minMeetingRooms(vector<Interval>& intervals) {
    vector<pair<int, int>> v;
    for (int i = 0; i < intervals.size(); i++) {
      v.push_back(make_pair(intervals[i].start, 1));
      v.push_back(make_pair(intervals[i].end, -1));
    }
    sort(v.begin(), v.end());
    int cnt = 0, ans = 0;
    for (int i = 0; i < v.size(); i++) {
      cnt += v[i].second;
      ans = max(ans, cnt);
    }
    return ans;
  }
};