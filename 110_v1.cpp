/*
  110_v1.cpp
  Balanced Binary Tree
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
  pair<bool, int> isBalancedWithDepth(TreeNode* root) {
    if (root == NULL) return make_pair(true, 0);
    auto p1 = isBalancedWithDepth(root->left);
    auto p2 = isBalancedWithDepth(root->right);
    int diff = abs(p1.second - p2.second);
    int newHeight = max(p1.second, p2.second) + 1;
    return make_pair(p1.first && p2.first && diff <= 1, newHeight);
  }

 public:
  bool isBalanced(TreeNode* root) { return isBalancedWithDepth(root).first; }
};