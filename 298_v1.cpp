/*
  298_v1.cpp
  Binary Tree Longest Consecutive Sequence

  My first submission got WA because I didn't handle the special case where root
  is NULL.
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
  int ans;

  void dfs(TreeNode* root, int len) {
    ans = max(ans, len);
    if (root->left) {
      if (root->left->val == root->val + 1)
        dfs(root->left, len + 1);
      else
        dfs(root->left, 1);
    }
    if (root->right) {
      if (root->right->val == root->val + 1)
        dfs(root->right, len + 1);
      else
        dfs(root->right, 1);
    }
  }

 public:
  int longestConsecutive(TreeNode* root) {
    if (root == NULL) return 0;
    ans = 0;
    dfs(root, 1);
    return ans;
  }
};