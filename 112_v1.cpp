/*
  112_v1.cpp
  Path Sum

  Initialy I thought when root == NULL we should return true for the case where
  sum == 0. Turns out I was wrong and contributed two WAs.
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
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return root->val == sum;
    int sumRemaining = sum - root->val;
    return hasPathSum(root->left, sumRemaining) ||
           hasPathSum(root->right, sumRemaining);
  }
};