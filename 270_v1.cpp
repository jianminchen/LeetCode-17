/*
  270_v1.cpp
  Closest Binary Search Tree Value
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
  int closestValue(TreeNode* root, double target) {
    const double EPS = 1e-8;
    int ret;
    double minDiffAbs;
    bool first = true;
    while (root != NULL) {
      double diff = root->val - target, diffAbs = fabs(diff);
      if (diffAbs < EPS)
        return root->val;
      else if (diff < -EPS) {
        if (first || diffAbs < minDiffAbs) {
          first = false;
          minDiffAbs = diffAbs;
          ret = root->val;
        }
        root = root->right;
      } else {
        if (first || diffAbs < minDiffAbs) {
          first = false;
          minDiffAbs = diffAbs;
          ret = root->val;
        }
        root = root->left;
      }
    }
    return ret;
  }
};