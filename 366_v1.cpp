/*
  366_v1.cpp
  Find Leaves of Binary Tree
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
  int removeLeaves(TreeNode* root, vector<vector<int>>& ret) {
    if (root == NULL) return -1;
    int leftDepth = removeLeaves(root->left, ret);
    int rightDepth = removeLeaves(root->right, ret);
    int depth = max(leftDepth, rightDepth) + 1;

    if (ret.size() > depth)
      ret[depth].push_back(root->val);
    else
      ret.push_back(vector<int>{root->val});

    delete root->left;
    delete root->right;
    root->left = root->right = NULL;

    return depth;
  }

 public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> ret;
    removeLeaves(root, ret);
    return ret;
  }
};