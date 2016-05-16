/*
  94_v1.cpp
  Binary Tree Inorder Traversal
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
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> ret;
    TreeNode* curr = root;
    while (curr != NULL) {
      st.push(curr);
      curr = curr->left;
    }
    while (!st.empty()) {
      curr = st.top();
      ret.push_back(curr->val);
      st.pop();
      curr = curr->right;
      while (curr != NULL) {
        st.push(curr);
        curr = curr->left;
      }
    }
    return ret;
  }
};