/*
  82_v1.cpp
  Remove Duplicates from Sorted List II
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *curr = head;
    while (curr != NULL) {
      ListNode* tmp = curr;
      int cnt = 0;
      while (tmp != NULL && tmp->val == curr->val) {
        cnt++;
        tmp = tmp->next;
      }
      if (cnt > 1)
        prev->next = tmp;
      else
        prev = curr;
      curr = tmp;
    }
    return dummy->next;
  }
};