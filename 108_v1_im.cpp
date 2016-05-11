/*
  108_v1_im.cpp
  Convert Sorted Array to Binary Search Tree

  There is no need to construct vectors in the recursive function, we only need
  to pass the [l, r] ranges.
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
  TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, l, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, r);
    return root;
  }

 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }
};