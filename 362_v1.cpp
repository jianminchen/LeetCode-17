/*
  362_v1.cpp
  Design Hit Counter

  My first submission got WA since I've used a pair of (cachedTimestamp,
  cachedTimestampHits) to mitigate the issue of extremely high QPS. However, one
  thing I haven't noticed - that pair may not have been pushed to the back of
  the deque when calling getHits().

  One more thing - my design here is not bad but not very optimal as well. A
  better idea is to use a vector pair<int, int> of size 300 to keep track of
  both the timestamp and the number of hits at that particular timestamp. We
  only need the values of the last 300 seconds and then getHits essentially is
  O(1) as well.
*/

class HitCounter {
 private:
  int cachedTimestamp, cachedTimestampHits, numHits;
  deque<pair<int, int>> q;

 public:
  /** Initialize your data structure here. */
  HitCounter() {
    cachedTimestampHits = 0;
    numHits = 0;
  }

  /** Record a hit.
      @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    numHits++;
    if (cachedTimestampHits == 0) {
      cachedTimestamp = timestamp;
      cachedTimestampHits = 1;
    } else {
      if (timestamp == cachedTimestamp)
        cachedTimestampHits++;
      else {
        q.emplace_back(cachedTimestamp, cachedTimestampHits);
        cachedTimestamp = timestamp;
        cachedTimestampHits = 1;
      }
    }
  }

  /** Return the number of hits in the past 5 minutes.
      @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    while (!q.empty()) {
      auto p = q.front();
      int frontTimestamp = p.first;
      if (timestamp - frontTimestamp >= 300) {
        numHits -= p.second;
        q.pop_front();
      } else {
        break;
      }
    }

    if (timestamp - cachedTimestamp >= 300) {
      numHits -= cachedTimestampHits;
      cachedTimestampHits = 0;
    }

    return numHits;
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */