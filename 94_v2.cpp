/*
  94_v2.cpp
  Binary Tree Inorder Traversal
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
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* curr = root;
    vector<int> ret;
    while (curr) {
      if (curr->left == NULL) {
        ret.push_back(curr->val);
        curr = curr->right;
      }

      else {
        TreeNode* prev = curr->left;
        while (prev->right != NULL && prev->right != curr) prev = prev->right;

        if (prev->right == NULL) {
          prev->right = curr;
          curr = curr->left;
        }

        else {
          prev->right = NULL;
          ret.push_back(curr->val);
          curr = curr->right;
        }
      }
    }
    return ret;
  }
};