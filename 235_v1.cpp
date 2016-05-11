/*
  235_v1.cpp
  Lowest Common Ancestor of a Binary Search Tree

  My first submission got CE.
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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p == q) return p;
    if (p == root || q == root) return root;
    if (p->val < root->val && q->val > root->val) return root;
    if (p->val > root->val && q->val < root->val) return root;
    if (p->val < root->val) return lowestCommonAncestor(root->left, p, q);
    return lowestCommonAncestor(root->right, p, q);
  }
};