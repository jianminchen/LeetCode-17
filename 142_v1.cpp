/*
  142_v1.cpp
  Linked List Cycle II
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
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (true) {
      if (slow == NULL) return NULL;
      slow = slow->next;
      if (fast == NULL || fast->next == NULL) return NULL;
      fast = fast->next->next;
      if (slow == fast) break;
    }
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};