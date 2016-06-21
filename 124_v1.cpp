/*
  124_v1.cpp
  Binary Tree Maximum Path Sum
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 private:
  pair<int, int> maxPath(TreeNode* root) {
    if (root == NULL) return make_pair(0, 0);
    auto p1 = maxPath(root->left);
    auto p2 = maxPath(root->right);
    int val1 = max(0, max(p1.first, p2.first)) + root->val;

    int val2 = root->val;
    if (p1.first > 0) val2 += p1.first;
    if (p2.first > 0) val2 += p2.first;
    if (root->left) val2 = max(val2, p1.second);
    if (root->right) val2 = max(val2, p2.second);

    return make_pair(val1, val2);
  }

 public:
  int maxPathSum(TreeNode* root) {
    auto p = maxPath(root);
    return p.second;
  }
};