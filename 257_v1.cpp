/*
  257_v1.cpp
  Binary Tree Paths
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    queue<pair<TreeNode*, string>> q;
    if (root == NULL) return ret;
    q.push(make_pair(root, to_string(root->val)));
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      TreeNode* curr = p.first;
      string path = p.second;
      if (curr->left == NULL && curr->right == NULL) ret.push_back(path);
      if (curr->left)
        q.push(make_pair(curr->left, path + "->" + to_string(curr->left->val)));
      if (curr->right)
        q.push(
            make_pair(curr->right, path + "->" + to_string(curr->right->val)));
    }
    return ret;
  }
};