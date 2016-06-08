/*
  250_v1.cpp
  Count Univalue Subtrees
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
  pair<bool, int> isUnivalSubtree(TreeNode* root, int val) {
    if (root == NULL) return make_pair(true, 0);
    bool f1 = root->val == val;
    auto f2 = isUnivalSubtree(root->left, val);
    auto f3 = isUnivalSubtree(root->right, val);
    if (f1 && f2.first && f3.first)
      return make_pair(true, f2.second + f3.second + 1);
    return make_pair(false, 0);
  }

 public:
  int countUnivalSubtrees(TreeNode* root) {
    if (root == NULL) return 0;
    auto p = isUnivalSubtree(root, root->val);
    if (p.first) return p.second;
    return countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right);
  }
};