/*
  98_v1.cpp
  Validate Binary Search Tree
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
  bool isValidBST(TreeNode* root, bool hasLowerBound, int lowerBound,
                  bool hasUpperBound, int upperBound) {
    if (root == NULL) return true;
    if (hasLowerBound && root->val <= lowerBound) return false;
    if (hasUpperBound && root->val >= upperBound) return false;
    return isValidBST(root->left, hasLowerBound, lowerBound, true, root->val) &&
           isValidBST(root->right, true, root->val, hasUpperBound, upperBound);
  }

 public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, false, 0, false, 0);
  }
};