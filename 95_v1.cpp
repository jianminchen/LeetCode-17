/*
  95_v1.cpp
  Unique Binary Search Trees II

  I was pretty retarded in my first submission as I've moved "TreeNode* root =
  new TreeNode(i)" right after the for loop.
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
  vector<TreeNode*> generateTrees(int numNodes, int minVal) {
    vector<TreeNode*> ret;
    if (numNodes == 0) return ret;
    if (numNodes == 1) {
      TreeNode* root = new TreeNode(minVal);
      ret.push_back(root);
      return ret;
    }
    for (int i = minVal; i <= minVal + numNodes - 1; i++) {
      vector<TreeNode *> leftRoot, rightRoot;
      leftRoot = generateTrees(i - minVal, minVal);
      rightRoot = generateTrees(minVal + numNodes - 1 - i, i + 1);
      // cout << numNodes << " " << i << " " << leftRoot.size() << " " <<
      // rightRoot.size() << endl;
      if (leftRoot.size() == 0) {
        for (int j = 0; j < rightRoot.size(); j++) {
          TreeNode* root = new TreeNode(i);
          root->right = rightRoot[j];
          ret.push_back(root);
        }
      }
      if (rightRoot.size() == 0) {
        for (int j = 0; j < leftRoot.size(); j++) {
          TreeNode* root = new TreeNode(i);
          root->left = leftRoot[j];
          ret.push_back(root);
        }
      }
      for (int j = 0; j < leftRoot.size(); j++) {
        for (int k = 0; k < rightRoot.size(); k++) {
          TreeNode* root = new TreeNode(i);
          root->left = leftRoot[j];
          root->right = rightRoot[k];
          ret.push_back(root);
        }
      }
    }
    return ret;
  }

 public:
  vector<TreeNode*> generateTrees(int n) { return generateTrees(n, 1); }
};