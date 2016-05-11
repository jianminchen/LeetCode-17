/*
  141_v1.cpp
  Linked List Cycle

  I was not thinking very clearly for my first two submissions. For my first
  submission I wrote something like "if (p == NULL) break;" inside the while
  loop. Apparently when any of the two pointer becomes NULL the original linked
  list cannot have a cycle. My second submission sets the while condition as
  "while (p != q)" instead of "while (true)". This fails the empty list input
  case.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    while (true) {
      if (p == NULL) return false;
      p = p->next;
      if (q == NULL) return false;
      q = q->next;
      if (q == NULL) return false;
      q = q->next;
      if (p == q) return true;
    }
    return true;
  }
};