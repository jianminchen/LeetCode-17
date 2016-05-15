/*
  203_v1.cpp
  Remove Linked List Elements
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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *curr = head, *prev = dummy;
    while (curr != NULL) {
      if (curr->val == val) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};