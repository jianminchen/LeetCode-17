/*
  129_v1.cpp
  Sum Root to Leaf Numbers
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
  int sum;
  void dfs(TreeNode* root, int num) {
    if (root->left == NULL && root->right == NULL) sum += num;
    if (root->left) dfs(root->left, num * 10 + root->left->val);
    if (root->right) dfs(root->right, num * 10 + root->right->val);
  }

 public:
  int sumNumbers(TreeNode* root) {
    sum = 0;
    if (root) dfs(root, root->val);
    return sum;
  }
};