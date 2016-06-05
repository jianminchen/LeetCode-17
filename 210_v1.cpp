/*
  210_v1.cpp
  Course Schedule II

  This problem does not have a "Run Code" option so I got a couple of CEs and
  RTEs.
*/

class Solution {
 private:
  vector<vector<int>> graph;
  vector<bool> visited, onstack;
  vector<int> indegree;
  bool hasCycle;

  void dfs(int curr, vector<int>& v) {
    onstack[curr] = true;
    visited[curr] = true;
    for (int i = 0; i < graph[curr].size(); i++) {
      int node = graph[curr][i];
      if (onstack[node]) hasCycle = true;
      if (!visited[node]) dfs(node, v);
    }
    onstack[curr] = false;
    v.push_back(curr);
  }

 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    graph.resize(numCourses);
    visited.resize(numCourses);
    onstack.resize(numCourses);
    indegree.resize(numCourses);
    hasCycle = false;
    for (int i = 0; i < numCourses; i++) {
      graph[i] = vector<int>();
      visited[i] = false;
    }
    for (int i = 0; i < prerequisites.size(); i++) {
      int a = prerequisites[i].first;
      int b = prerequisites[i].second;
      graph[b].push_back(a);
      indegree[a]++;
    }
    vector<int> ret, nodes;
    for (int i = 0; i < numCourses; i++) {
      if (!visited[i] && indegree[i] == 0) {
        dfs(i, nodes);
        if (hasCycle) return vector<int>();
      }
    }
    reverse(nodes.begin(), nodes.end());
    for (int i = 0; i < nodes.size(); i++) ret.push_back(nodes[i]);
    if (ret.size() != numCourses) return vector<int>();
    return ret;
  }
};