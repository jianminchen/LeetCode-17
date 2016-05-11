/*
  108_v1.cpp
  Convert Sorted Array to Binary Search Tree
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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return NULL;
    TreeNode* root = new TreeNode(nums[n / 2]);
    vector<int> l, r;
    for (int i = 0; i < n / 2; i++) l.push_back(nums[i]);
    for (int i = n / 2 + 1; i < n; i++) r.push_back(nums[i]);
    root->left = sortedArrayToBST(l);
    root->right = sortedArrayToBST(r);
    return root;
  }
};