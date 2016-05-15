/*
  107_v1.cpp
  Binary Tree Level Order Traversal II
*/

/**
*Definition for a binary tree node.
*struct TreeNode {
*    int val;
*    TreeNode *left;
*    TreeNode *right;
*    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
*};
*/
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret;
    queue<pair<TreeNode*, int>> q;
    if (root) q.push(make_pair(root, 0));
    int prevLen = 0;
    vector<int> v;
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (p.second != prevLen) {
        prevLen = p.second;
        ret.push_back(v);
        v.clear();
      }
      v.push_back(p.first->val);
      if (p.first->left) q.push(make_pair(p.first->left, p.second + 1));
      if (p.first->right) q.push(make_pair(p.first->right, p.second + 1));
    }
    if (!v.empty()) ret.push_back(v);
    reverse(ret.begin(), ret.end());
    return ret;
  }
};