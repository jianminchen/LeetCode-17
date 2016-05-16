/*
  144_v1.cpp
  Binary Tree Preorder Traversal
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
  vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = root;
    vector<int> ret;
    while (curr != NULL) {
      st.push(curr);
      ret.push_back(curr->val);
      curr = curr->left;
    }
    while (!st.empty()) {
      curr = st.top();
      st.pop();
      curr = curr->right;
      while (curr != NULL) {
        st.push(curr);
        ret.push_back(curr->val);
        curr = curr->left;
      }
    }
    return ret;
  }
};