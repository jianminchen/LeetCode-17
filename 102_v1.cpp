/*
  102_v1.cpp
  Binary Tree Level Order Traversal
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
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (root == NULL) return ret;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> currentLevelNodes;
      int numCurrentLevelNodes = q.size();
      for (int i = 0; i < numCurrentLevelNodes; i++) {
        TreeNode* currNode = q.front();
        q.pop();
        currentLevelNodes.push_back(currNode->val);
        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
      }
      ret.push_back(currentLevelNodes);
    }
    return ret;
  }
};