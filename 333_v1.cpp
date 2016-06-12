/*
  333_v1.cpp
  Largest BST Subtree

  My first two submissions are based on an incorrect solution - I'm validating
  whether a tree is a BST using a top-down approach. But apparently this won't
  work since essentially for this problem we need to validate whether a tree is
  a BST using a bottom-up approach.
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
  int largestBSTSize;

  bool isBST(TreeNode* root, int& minVal, int& maxVal, int& treeSize) {
    minVal = maxVal = treeSize = 0;

    if (root == NULL) return true;

    int leftSubtreeMin, leftSubtreeMax, leftSubtreeSize;
    bool isLeftBST =
        isBST(root->left, leftSubtreeMin, leftSubtreeMax, leftSubtreeSize);
    int rightSubtreeMin, rightSubtreeMax, rightSubtreeSize;
    bool isRightBST =
        isBST(root->right, rightSubtreeMin, rightSubtreeMax, rightSubtreeSize);

    if (isLeftBST && isRightBST) {
      bool leftValid = false, rightValid = false;
      if (leftSubtreeSize == 0 || leftSubtreeMax < root->val) leftValid = true;
      if (rightSubtreeSize == 0 || rightSubtreeMin > root->val)
        rightValid = true;
      if (leftValid && rightValid) {
        if (leftSubtreeSize == 0)
          minVal = root->val;
        else
          minVal = leftSubtreeMin;

        if (rightSubtreeSize == 0)
          maxVal = root->val;
        else
          maxVal = rightSubtreeMax;
        treeSize = leftSubtreeSize + rightSubtreeSize + 1;
        // cout << root -> val << " " << treeSize << endl;
        largestBSTSize = max(largestBSTSize, treeSize);
        return true;
      }
    }

    return false;
  }

 public:
  int largestBSTSubtree(TreeNode* root) {
    largestBSTSize = 0;
    int minVal, maxVal, treeSize;
    isBST(root, minVal, maxVal, treeSize);
    return largestBSTSize;
  }
};