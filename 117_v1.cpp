/*
  117_v1.cpp
  Populating Next Right Pointers in Each Node II

  This code is exacty the same as 116_v1.cpp.
*/

/**
*Definition for binary tree with next pointer.
*struct TreeLinkNode {
* int val;
* TreeLinkNode *left, *right, *next;
* TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
*};
*/
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *curr = root, *head = NULL, *tail = NULL;
    while (curr) {
      if (curr->left) {
        if (tail == NULL)
          head = tail = curr->left;
        else {
          tail->next = curr->left;
          tail = tail->next;
        }
      }
      if (curr->right) {
        if (tail == NULL)
          head = tail = curr->right;
        else {
          tail->next = curr->right;
          tail = tail->next;
        }
      }
      curr = curr->next;
      if (curr == NULL) {
        curr = head;
        head = tail = NULL;
      }
    }
  }
};