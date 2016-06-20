/*
  332_v1.cpp
  Reconstruct Itinerary

  I've completely got the Eulerian path algorithm incorrectly for my first
  submission. I know it has something to do with DFS but just forgot how.
*/

class Solution {
 private:
  unordered_map<string, multiset<string>> graph;

  void dfs(string curr, vector<string>& ret) {
    while (graph[curr].size()) {
      string next = *graph[curr].begin();
      graph[curr].erase(graph[curr].begin());
      dfs(next, ret);
    }
    ret.push_back(curr);
  }

 public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (int i = 0; i < tickets.size(); i++) {
      string start = tickets[i].first;
      string end = tickets[i].second;
      graph[start].insert(end);
    }
    vector<string> ret;
    dfs("JFK", ret);
    reverse(ret.begin(), ret.end());
    return ret;
  }
};