/*
  310_v1.cpp
  Minimum Height Trees
*/

class Solution {
 private:
  vector<vector<int>> graph;
  vector<bool> visited;

  void dfs(int curr, int depth, int& maxdepth, int& furthestnode,
           vector<int>& path, vector<int>& longestpath) {
    visited[curr] = true;
    path.push_back(curr);
    if (depth > maxdepth) {
      maxdepth = depth;
      furthestnode = curr;
      longestpath = path;
    }
    for (int i = 0; i < graph[curr].size(); i++) {
      int next = graph[curr][i];
      if (!visited[next])
        dfs(next, depth + 1, maxdepth, furthestnode, path, longestpath);
    }
    path.pop_back();
  }

 public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    graph.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < n; i++) graph[i].clear();
    for (int i = 0; i < edges.size(); i++) {
      int a = edges[i].first;
      int b = edges[i].second;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    int maxDepth = -1, furthestNode;
    vector<int> path, longestpath;
    dfs(0, 0, maxDepth, furthestNode, path, longestpath);
    path.clear();
    longestpath.clear();
    maxDepth = -1;
    int tmpNode;
    fill(visited.begin(), visited.end(), false);
    dfs(furthestNode, 0, maxDepth, tmpNode, path, longestpath);
    int sz = longestpath.size();
    if (sz % 2 == 1)
      return vector<int>{longestpath[sz / 2]};
    else
      return vector<int>{longestpath[sz / 2 - 1], longestpath[sz / 2]};
  }
};