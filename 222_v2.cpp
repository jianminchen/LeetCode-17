/*
  222_v2.cpp
  Count Complete Tree Nodes

  This version is completely copied from this discussion:
  https://leetcode.com/discuss/38930/concise-java-solutions-o-log-n-2. It firsts
  calculate the height of the tree by going to the left node ONLY. Then for each
  recursive call we only need to calculate the height of the right subtree to
  determine which way we should go in countNodes(), very nice.
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
  int height(TreeNode* root) {
    if (root == NULL) return -1;
    return 1 + height(root->left);
  }

 public:
  int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    int h = height(root);
    if (height(root->right) == h - 1)
      return (1 << h) + countNodes(root->right);
    else
      return (1 << h - 1) + countNodes(root->left);
  }
};