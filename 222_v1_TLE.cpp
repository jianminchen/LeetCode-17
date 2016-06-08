/*
  222_v1_TLE.cpp
  Count Complete Tree Nodes

  Although I roughly get the idea of calculating maxHeight and the number of
  nodes @ maxHeight, the time complexity of the algorithm is still O(n) and thus
  doesn't make sense at all. But I didn't expect they can find a way to TLE a
  linear algorithm - albeit a naive one.
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
  int maxHeight, numNodes;
  void countNodes(TreeNode* root, int height) {
    if (height == maxHeight)
      numNodes++;
    else if (height > maxHeight)
      maxHeight = height, numNodes = 1;
    if (root->left) countNodes(root->left, height + 1);
    if (root->right) countNodes(root->right, height + 1);
  }

 public:
  int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    maxHeight = numNodes = 0;
    countNodes(root, 0);
    int ret = (1 << maxHeight) - 1 + numNodes;
    return ret;
  }
};