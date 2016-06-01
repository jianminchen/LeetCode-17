/*
  147_v1.cpp
  Insertion Sort List

  The problem with my first submission is I have made an incorrect assumption
  about the loop invariant of this problem. Although I've used a dummy node. In
  fact I should initialize dummy -> next = NULL instead of dummy -> next = head
  as I normally do. This is because throughout the whole process we are trying
  to insert a node into the list started from dummy and it doesn't make sense to
  link head with dummy at the very start. My first submission got RTE.
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
  ListNode *insertionSortList(ListNode *head) {
    if (head == NULL) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = NULL;
    ListNode *curr = head;
    while (curr != NULL) {
      ListNode *nextNode = curr->next;
      ListNode *tmp = dummy->next, *prev = dummy;
      while (tmp != NULL) {
        if (tmp->val > curr->val) {
          prev->next = curr;
          curr->next = tmp;
          break;
        }
        prev = tmp;
        tmp = tmp->next;
      }
      if (tmp == NULL) {
        prev->next = curr;
        curr->next = NULL;
      }
      curr = nextNode;
    }
    return dummy->next;
  }
};