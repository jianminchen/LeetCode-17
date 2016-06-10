/*
  109_v1.cpp
  Convert Sorted List to Binary Search Tree
*/

/**
*Definition for singly-linked list.
*struct ListNode {
*    int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(NULL) {}
*};
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
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode* curr = head;
    int listLen = 0;
    while (curr != NULL) {
      listLen++;
      curr = curr->next;
    }
    ListNode* prev = NULL;
    curr = head;
    int cnt = 1;
    while (cnt <= listLen / 2) {
      cnt++;
      prev = curr;
      curr = curr->next;
    }
    TreeNode* root = new TreeNode(curr->val);
    if (prev != NULL) {
      prev->next = NULL;
      root->left = sortedListToBST(head);
    }
    if (curr->next != NULL) root->right = sortedListToBST(curr->next);
    return root;
  }
};