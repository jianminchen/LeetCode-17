/*
  173_v1.cpp
  Binary Search Tree Iterator

  My first submission didn't temporarily store the top node of the stack and got
  RTE.
*/

/**
*Definition for binary tree
*struct TreeNode {
*    int val;
*    TreeNode *left;
*    TreeNode *right;
*    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
*};
*/
class BSTIterator {
 private:
  stack<TreeNode*> path;

 public:
  BSTIterator(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != NULL) {
      path.push(curr);
      curr = curr->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !path.empty(); }

  /** @return the next smallest number */
  int next() {
    TreeNode* tmp = path.top();
    path.pop();
    TreeNode* curr = tmp->right;
    while (curr != NULL) {
      path.push(curr);
      curr = curr->left;
    }
    return tmp->val;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */