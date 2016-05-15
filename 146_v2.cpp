/*
  146_v2.cpp
  LRU Cache

  In this version I've implemented a common method moveKeyToFront(). In
  146_v1.cpp I'm moving the key to the back of the list whenever it has been
  accessed. However, this also means we need to write some more statements to
  get the iterator pointing to the back element, as opposed to moving the key to
  the front of list where we can just get the iterator using l.begin().

  My first submission got CE and my second submission got WA since I've
  mistakenly removed the front element when l.size() == maxCapacity.
*/

class LRUCache {
  unordered_map<int, list<pair<int, int>>::iterator> m;
  list<pair<int, int>> l;
  int maxCapacity;

  void moveKeyToFront(list<pair<int, int>>::iterator it) {
    pair<int, int> kvp = *it;
    l.erase(it);
    m.erase(kvp.first);
    l.push_front(kvp);
    m[kvp.first] = l.begin();
  }

 public:
  LRUCache(int capacity) {
    m.clear();
    l.clear();
    maxCapacity = capacity;
  }

  int get(int key) {
    if (m.find(key) == m.end()) return -1;
    auto it = m[key];
    int val = it->second;
    moveKeyToFront(it);
    return val;
  }

  void set(int key, int value) {
    if (m.find(key) != m.end()) {
      auto it = m[key];
      it->second = value;
      moveKeyToFront(it);
    } else {
      if (l.size() == maxCapacity) {
        int keyToRemove = l.back().first;
        m.erase(keyToRemove);
        l.pop_back();
      }
      l.push_front(make_pair(key, value));
      m[key] = l.begin();
    }
  }
};