/*
  359_v1.cpp
  Logger Rate Limiter
*/

class Logger {
 private:
  unordered_map<string, int> m;

 public:
  /** Initialize your data structure here. */
  Logger() { m.clear(); }

  /** Returns true if the message should be printed in the given timestamp,
   * otherwise returns false. The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (m.find(message) == m.end()) {
      m[message] = timestamp;
      return true;
    } else {
      int prevTimestamp = m[message];
      if (timestamp - prevTimestamp < 10) return false;
      m[message] = timestamp;
      return true;
    }
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */