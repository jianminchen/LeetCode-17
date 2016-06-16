/*
  285_v1.cpp
  Inorder Successor in BST

  My first submission got CE. My second and third submissions got WA and RTE.
  Then I've moved TreeNode* ans outside as a member of the class instead of
  keeping it in the argument list.

  But actually I've just found this is a BST, so oops...my solution didn't use
  this characteristic at all...
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
  TreeNode *prev, *ans;
  void inorder(TreeNode* root, TreeNode* p) {
    if (root->left) inorder(root->left, p);
    if (prev != NULL && prev->val == p->val) ans = root;
    prev = root;
    if (root->right) inorder(root->right, p);
  }

 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    prev = NULL;
    ans = NULL;
    inorder(root, p);
    return ans;
  }
};