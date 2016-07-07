/*
  145_v1.cpp
  Binary Tree Postorder Traversal
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
  vector<int> postorderTraversal(TreeNode* root) {
    TreeNode* curr = root;
    vector<int> ret;
    while (curr) {
      if (curr->right == NULL) {
        ret.push_back(curr->val);
        curr = curr->left;
      }

      else {
        TreeNode* prev = curr->right;
        while (prev->left != NULL && prev->left != curr) prev = prev->left;

        if (prev->left == NULL) {
          prev->left = curr;
          ret.push_back(curr->val);
          curr = curr->right;
        }

        else {
          prev->left = NULL;
          curr = curr->left;
        }
      }
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};