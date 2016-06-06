/*
  113_v1.cpp
  Path Sum II
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
  void solve(TreeNode* root, int remaining, vector<int>& v,
             vector<vector<int>>& ret) {
    if (root->left == NULL && root->right == NULL) {
      if (remaining == 0) ret.push_back(v);
      return;
    }
    if (root->left) {
      v.push_back(root->left->val);
      solve(root->left, remaining - root->left->val, v, ret);
      v.pop_back();
    }
    if (root->right) {
      v.push_back(root->right->val);
      solve(root->right, remaining - root->right->val, v, ret);
      v.pop_back();
    }
  }

 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ret;
    vector<int> v;
    if (root) {
      v.push_back(root->val);
      solve(root, sum - root->val, v, ret);
    }
    return ret;
  }
};