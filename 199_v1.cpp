/*
  199_v1.cpp
  Binary Tree Right Side View
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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    if (root == NULL) return ret;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int numNodes = q.size();
      for (int i = 0; i < numNodes; i++) {
        TreeNode* curr = q.front();
        q.pop();
        if (i == numNodes - 1) ret.push_back(curr->val);
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }
    return ret;
  }
};