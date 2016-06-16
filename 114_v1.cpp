/*
  114_v1.cpp
  Flatten Binary Tree to Linked List
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
 private:
  TreeNode* prev;
  void preOrder(TreeNode* root) {
    if (prev != NULL) prev->right = root;
    prev = root;
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    if (root->right) preOrder(root->right);
    if (tmp) preOrder(tmp);
  }

 public:
  void flatten(TreeNode* root) {
    if (root == NULL) return;
    prev = NULL;
    preOrder(root);
  }
};