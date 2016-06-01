/*
  337_v1.cpp
  House Robber III

  One special issue I'd like to point out is related to changing cache from map
  to unordered_map
  (http://stackoverflow.com/questions/4870437/pairint-int-pair-as-key-of-unordered-map-issue).
  The issue here is std doesn't know how to hash a pair<int, int> so we cannot
  declare unordered_map<pair<TreeNode*, int>, int> cache, or even
  unordered_map<pair<int, int>, int> cache without defining our hash function
  here.

  One example of defining a hash function is shown here:
  http://stackoverflow.com/questions/32685540/c-unordered-map-with-pair-as-key-not-compiling

  My first submission got TLE since I've basically solved the problem in a brute
  force recursive style without using any cache. In fact even if I implement the
  problem in a not-so-stupid way it will get accepted without the need of a
  cache. My second submission got CE.
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
  map<pair<TreeNode*, int>, int> cache;

  int dp(TreeNode* root, int robRoot) {
    if (root == NULL) return 0;
    auto p = make_pair(root, robRoot);
    if (cache.find(p) != cache.end()) return cache[p];
    if (robRoot == 1)
      return cache[p] = root->val + dp(root->left, 0) + dp(root->right, 0);
    else {
      int maxLeft = max(dp(root->left, 0), dp(root->left, 1));
      int maxRight = max(dp(root->right, 0), dp(root->right, 1));
      return cache[p] = maxLeft + maxRight;
    }
  }

 public:
  int rob(TreeNode* root) {
    cache.clear();
    if (root == NULL) return 0;
    return max(dp(root, 0), dp(root, 1));
  }
};