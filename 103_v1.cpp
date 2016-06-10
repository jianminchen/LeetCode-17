/*
  103_v1.cpp
  Binary Tree Zigzag Level Order Traversal
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
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (root == NULL) return ret;
    queue<TreeNode*> q;
    q.push(root);
    bool flag = false;
    while (!q.empty()) {
      int sz = q.size();
      vector<int> v;
      for (int i = 0; i < sz; i++) {
        TreeNode* curr = q.front();
        q.pop();
        v.push_back(curr->val);
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
      if (flag) reverse(v.begin(), v.end());
      ret.push_back(v);
      flag = !flag;
    }
    return ret;
  }
};