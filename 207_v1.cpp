/*
  207_v1.cpp
  Course Schedule

  My first two submissions basically don't make sense at all...
*/

class Solution {
 private:
  bool dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited,
           vector<bool>& onStack) {
    visited[curr] = true;
    onStack[curr] = true;
    for (int i = 0; i < graph[curr].size(); i++) {
      int next = graph[curr][i];
      if (onStack[next]) return false;
      if (!visited[next]) {
        if (!dfs(next, graph, visited, onStack)) return false;
      }
    }
    onStack[curr] = false;
    return true;
  }

 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<bool> visited(numCourses, false);
    vector<bool> onStack(numCourses, false);
    for (int i = 0; i < prerequisites.size(); i++) {
      int a = prerequisites[i].first;
      int b = prerequisites[i].second;
      graph[b].push_back(a);
    }
    for (int i = 0; i < numCourses; i++) {
      if (!visited[i]) {
        if (!dfs(i, graph, visited, onStack)) return false;
      }
    }
    return true;
  }
};