/*
  83_v1.cpp
  Remove Duplicates from Sorted List
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *curr = head, *prev = NULL;
    while (curr != NULL) {
      if (prev && curr->val == prev->val) {
        prev->next = curr->next;
        ListNode *tmp = curr;
        curr = curr->next;
        delete tmp;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    return head;
  }
};