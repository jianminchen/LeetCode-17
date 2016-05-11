/*
  237_v1.cpp
  Delete Node in a Linked List

  I forgot to save node -> next as a temporary variable and directly tried
  "delete node -> next" in the first submission and got RTE.
*/

/**
*Definition for singly-linked list.
*struct ListNode {
*    int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(NULL) {}
*};
*/
class Solution {
 public:
  void deleteNode(ListNode* node) {
    ListNode* tmp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete tmp;
  }
};