/*
  133_v1.cpp
  Clone Graph

  My first submission got CE and my second submission did not handle the special
  case where node == NULL.
*/

/**
*Definition for undirected graph.
*struct UndirectedGraphNode {
*    int label;
*    vector<UndirectedGraphNode *> neighbors;
*    UndirectedGraphNode(int x) : label(x) {};
*};
*/
class Solution {
 private:
  map<UndirectedGraphNode*, UndirectedGraphNode*> hash;

  UndirectedGraphNode* dfs(UndirectedGraphNode* curr) {
    hash[curr] = new UndirectedGraphNode(curr->label);
    for (int i = 0; i < curr->neighbors.size(); i++) {
      UndirectedGraphNode* next = curr->neighbors[i];
      if (hash.find(next) != hash.end())
        hash[curr]->neighbors.push_back(hash[next]);
      else
        hash[curr]->neighbors.push_back(dfs(next));
    }
    return hash[curr];
  }

 public:
  UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
    if (node == NULL) return NULL;
    return dfs(node);
  }
};