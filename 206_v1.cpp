/*
  206_v1.cpp
  Reverse Linked List
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
  ListNode* reverseList(ListNode* head) {
    ListNode* curr = head, * prev = NULL;
    while (curr != NULL) {
      ListNode* tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    return prev;
  }
};