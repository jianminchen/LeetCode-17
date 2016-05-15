/*
  19_v1.cpp
  Remove Nth Node From End of List
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *a = head, *b = head, *prev = dummy;
    for (int i = 0; i < n; i++) b = b->next;
    while (b != NULL) {
      prev = a;
      a = a->next;
      b = b->next;
    }
    if (prev) prev->next = a->next;
    delete a;
    return dummy->next;
  }
};