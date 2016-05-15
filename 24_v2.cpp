/*
  24_v2.cpp
  Swap Nodes in Pairs
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
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *a = head, *b = NULL;
    if (a && a->next) b = a->next;
    while (a && b) {
      ListNode *nextNode = b->next;
      prev->next = b;
      b->next = a;
      a->next = nextNode;
      prev = a;
      a = a->next;
      b = NULL;
      if (a && a->next) b = a->next;
    }
    return dummy->next;
  }
};