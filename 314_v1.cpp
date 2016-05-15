/*
  314_v1.cpp
  Binary Tree Vertical Order Traversal

  I forgot to check the special case where root == NULL so I got my first WA.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (root == NULL) return ret;
    map<int, vector<int>> m;
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      TreeNode* curr = p.first;
      int colIdx = p.second;
      m[colIdx].push_back(curr->val);
      if (curr->left) q.push(make_pair(curr->left, colIdx - 1));
      if (curr->right) q.push(make_pair(curr->right, colIdx + 1));
    }
    for (auto p : m) ret.push_back(p.second);
    return ret;
  }
};