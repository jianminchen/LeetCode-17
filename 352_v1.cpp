/*
  352_v1.cpp
  Data Stream as Disjoint Intervals

  Though my code got accepted this is really lengthy and bad. My first
  submission contains a bug, e.g. when I'm checking whether I can actually
  insert this interval I forgot to check the "in-between" case, e.g. inserting a
  7 when the set already contains [6, 8].

  I will try to improve this code in the next iteration.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class IntervalComparer {
 public:
  bool operator()(Interval a, Interval b) {
    return a.start < b.start || (a.start == b.start && a.end < b.end);
  }
};

class SummaryRanges {
 private:
  set<Interval, IntervalComparer> s;

 public:
  /** Initialize your data structure here. */
  SummaryRanges() { s.clear(); }

  void addNum(int val) {
    auto it = s.upper_bound(Interval(val, val));

    auto prev = it;
    if (it != s.begin()) prev--;

    pair<set<Interval>::iterator, bool> inserted;

    if (it != s.end()) {
      int intervalStart = it->start;
      if (intervalStart != val) {
        if (intervalStart == val + 1) {
          int intervalEnd = it->end;
          s.erase(it);
          inserted = s.insert(Interval(val, intervalEnd));
        } else {
          if (it == s.begin() || prev->end <= val)
            inserted = s.insert(Interval(val, val));
        }
      }
    } else {
      if (it == s.begin() || prev->end <= val)
        inserted = s.insert(Interval(val, val));
    }

    if (!inserted.second || inserted.first == s.begin()) return;

    prev = inserted.first;
    prev--;
    if (prev->end == val || prev->end == val - 1) {
      int intervalStart = prev->start;
      int intervalEnd = (inserted.first)->end;
      s.erase(prev);
      s.erase(inserted.first);
      s.insert(Interval(intervalStart, (inserted.first)->end));
    }
  }

  vector<Interval> getIntervals() {
    vector<Interval> ret;
    for (auto interval : s) ret.push_back(interval);
    return ret;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */