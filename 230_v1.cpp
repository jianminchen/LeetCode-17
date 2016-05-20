/*
  230_v1.cpp
  Kth Smallest Element in a BST
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
  int size(TreeNode* root) {
    if (root == NULL) return 0;
    return size(root->left) + size(root->right) + 1;
  }

 public:
  int kthSmallest(TreeNode* root, int k) {
    int leftSubTreeSize = size(root->left);
    if (k <= leftSubTreeSize)
      return kthSmallest(root->left, k);
    else if (leftSubTreeSize + 1 == k)
      return root->val;
    else
      return kthSmallest(root->right, k - leftSubTreeSize - 1);
  }
};