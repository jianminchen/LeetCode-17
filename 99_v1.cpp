/*
  99_v1.cpp
  Recover Binary Search Tree

  I've actually solved this problem on InterviewBit before. Sadly the last time
  I tried to solve it I also peeked at a LeetCode discussion and basically used
  the same code. But today I still struggled at this problem for 30 minutes and
  failed.

  The idea is simple, after inorder traversal you get a sequence of almost
  sorted values where one pair has been swapped. You need to find out the
  swapped pair.

  Interestingly, this simple problem cost me 30 minutes to solve and in fact
  after 30 minutes my submission still got WA.

  The idea is simple, find out all consecutive inversions, basically swapping a
  pair of values would create either 1 or 2 consecutive inversions in the new
  sequence. If the sequence only contains 2 elements then it is going to be 1
  inversion, otherwise it is going to be 2 inversions. The first element in the
  first inversion and the second element in the second inversion would be the
  answer. (Pay special attention to the one inversion case and the code used a
  small trick to "unify" these two cases.)

  Again the ideal solution of this problem involves in-order Morris traversal
  but I really don't understand that part.

  For studying Morris traversal:
  http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
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
  TreeNode *firstElement, *secondElement, *prev;

  void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    if (prev->val > root->val) {
      if (firstElement == NULL) {
        // printf("firstElement: prev = %d, root = %d\n", prev -> val, root ->
        // val);
        firstElement = prev;
      }
      if (firstElement != NULL) {
        // printf("secondElement: prev = %d, root = %d\n", prev -> val, root ->
        // val);
        secondElement = root;
      }
    }
    prev = root;
    inOrder(root->right);
  }

 public:
  void recoverTree(TreeNode* root) {
    firstElement = secondElement = NULL;
    prev = new TreeNode(INT_MIN);
    inOrder(root);
    swap(firstElement->val, secondElement->val);
  }
};