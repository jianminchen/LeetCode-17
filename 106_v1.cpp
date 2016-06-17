/*
  106_v1.cpp
  Construct Binary Tree from Inorder and Postorder Traversal
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
  TreeNode* buildTree(vector<int>& inorder, int inorderLeft, int inorderRight,
                      vector<int>& postorder, int postorderLeft,
                      int postorderRight) {
    TreeNode* root = new TreeNode(postorder[postorderRight]);
    int size = postorderRight - postorderLeft + 1;
    if (size == 1)
      return root;
    else {
      int inorderRootIdx = -1;
      for (int i = inorderLeft; i <= inorderRight; i++) {
        if (inorder[i] == root->val) {
          inorderRootIdx = i;
          break;
        }
      }
      int leftSubtreeSize = inorderRootIdx - inorderLeft;
      int rightSubtreeSize = inorderRight - inorderRootIdx;
      if (leftSubtreeSize > 0)
        root->left =
            buildTree(inorder, inorderLeft, inorderRootIdx - 1, postorder,
                      postorderLeft, postorderLeft + leftSubtreeSize - 1);
      if (rightSubtreeSize > 0)
        root->right =
            buildTree(inorder, inorderRootIdx + 1, inorderRight, postorder,
                      postorderRight - rightSubtreeSize, postorderRight - 1);
      return root;
    }
  }

 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0) return NULL;
    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1);
  }
};