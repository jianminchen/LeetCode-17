/*
  101_v1.cpp
  Symmetric Tree

  I forgot to check the special case where b == NULL in isSymmetric(TreeNode*,
  TreeNode*) and got my first WA.
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
  bool isSymmetric(TreeNode* a, TreeNode* b) {
    if (a == NULL) return b == NULL;
    if (b == NULL) return a == NULL;
    return a->val == b->val && isSymmetric(a->left, b->right) &&
           isSymmetric(a->right, b->left);
  }

 public:
  bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return isSymmetric(root->left, root->right);
  }
};