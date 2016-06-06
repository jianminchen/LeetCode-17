/*
  261_v1.cpp
  Graph Valid Tree
*/

class Solution {
 private:
  vector<vector<int>> graph;
  vector<bool> visited;

  void dfs(int curr) {
    visited[curr] = true;
    for (int i = 0; i < graph[curr].size(); i++) {
      int nextNode = graph[curr][i];
      if (!visited[nextNode]) dfs(nextNode);
    }
  }

 public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    graph.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    int numEdges = 0;
    for (int i = 0; i < edges.size(); i++) {
      int a = edges[i].first, b = edges[i].second;
      graph[a].push_back(b);
      graph[b].push_back(a);
      numEdges++;
    }
    if (numEdges != n - 1) return false;
    int numConnectedComponents = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        numConnectedComponents++;
        dfs(i);
      }
    }
    return numConnectedComponents == 1;
  }
};