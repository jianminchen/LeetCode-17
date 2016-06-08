/*
  105_v1.cpp
  Construct Binary Tree from Preorder and Inorder Traversal
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
  TreeNode* buildTree(vector<int>& preorder, int preorderStartIdx,
                      int preorderEndIdx, vector<int>& inorder,
                      int inorderStartIdx, int inorderEndIdx) {
    // cout << preorderStartIdx << " " << preorderEndIdx << " " <<
    // inorderStartIdx << " " << inorderEndIdx << endl;
    if (preorderStartIdx > preorderEndIdx) return NULL;
    int rootVal = preorder[preorderStartIdx], rootIdx = -1;
    for (int i = inorderStartIdx; i <= inorderEndIdx; i++) {
      if (inorder[i] == rootVal) {
        rootIdx = i;
        break;
      }
    }
    int leftSize = rootIdx - inorderStartIdx;
    TreeNode* root = new TreeNode(rootVal);
    root->left =
        buildTree(preorder, preorderStartIdx + 1, preorderStartIdx + leftSize,
                  inorder, inorderStartIdx, inorderStartIdx + leftSize - 1);
    root->right =
        buildTree(preorder, preorderStartIdx + leftSize + 1, preorderEndIdx,
                  inorder, inorderStartIdx + leftSize + 1, inorderEndIdx);
    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    if (n == 0) return NULL;
    return buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
  }
};