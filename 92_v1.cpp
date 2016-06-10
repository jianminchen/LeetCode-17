/*
  92_v1.cpp
  Reverse Linked List II
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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *curr = head, *prev = dummy;
    int cnt = 1;
    while (cnt < m) {
      cnt++;
      prev = curr;
      curr = curr->next;
    }
    ListNode* before = prev;  // (m - 1)th node
    ListNode* rHead = curr;   // mth node
    ListNode* tmp;
    prev = NULL;
    while (cnt <= n) {
      cnt++;
      tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    before->next = prev;
    rHead->next = curr;
    return dummy->next;
  }
};