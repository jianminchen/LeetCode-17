/*
  323_v1.cpp
  Number of Connected Components in an Undirected Graph
*/

class Solution {
  vector<vector<int>> graph;
  vector<bool> visited;
  void dfs(int curr, int n) {
    visited[curr] = true;
    for (int i = 0; i < graph[curr].size(); i++) {
      int next = graph[curr][i];
      if (!visited[next]) dfs(next, n);
    }
  }

 public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    graph.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    graph.clear();
    for (int i = 0; i < edges.size(); i++) {
      int a = edges[i].first, b = edges[i].second;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    int numComponents = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, n);
        numComponents++;
      }
    }
    return numComponents;
  }
};