/*
  347_v1.cpp
  Top K Frequent Elements

  I was handling the "pop - push" part incorrectly in the first submission and
  got WA.
*/

class Compare {
 public:
  bool operator()(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
  }
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) m[nums[i]]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    for (auto it : m) {
      pair<int, int> p = make_pair(it.first, it.second);
      if (pq.size() == k) {
        if (p.second > pq.top().second) {
          pq.pop();
          pq.push(p);
        }
      } else {
        pq.push(p);
      }
    }
    vector<int> ret;
    while (!pq.empty()) {
      ret.push_back(pq.top().first);
      pq.pop();
    }
    return ret;
  }
};