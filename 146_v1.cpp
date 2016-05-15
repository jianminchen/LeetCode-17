/*
  146_v1.cpp
  LRU Cache

  I've got 8 CEs. I've received two RTEs because I forgot to move the most
  recently used element to the end of the list. I've also got one TLE because
  I've tried to output some debug information and cout TLEd me.
*/

class LRUCache {
  unordered_map<int, list<pair<int, int>>::iterator> m;
  list<pair<int, int>> l;
  int maxCapacity;

 public:
  LRUCache(int capacity) {
    m.clear();
    l.clear();
    maxCapacity = capacity;
  }

  int get(int key) {
    // cout << "get " << key << endl;
    if (m.find(key) == m.end()) return -1;
    auto it = m[key];
    int val = it->second;
    l.erase(it);
    m.erase(key);
    l.push_back(make_pair(key, val));
    it = l.end();
    it--;
    m[key] = it;
    return val;
  }

  void set(int key, int value) {
    // cout << "set " << key << " " << value << endl;
    if (m.find(key) != m.end()) {
      auto it = m[key];
      l.erase(it);
      m.erase(key);
      l.push_back(make_pair(key, value));
      it = l.end();
      it--;
      m[key] = it;
    } else {
      if (l.size() == maxCapacity) {
        int keyToRemove = l.begin()->first;
        l.erase(l.begin());
        m.erase(keyToRemove);
      }
      l.push_back(make_pair(key, value));
      auto it = l.end();
      it--;
      m[key] = it;
    }
  }
};