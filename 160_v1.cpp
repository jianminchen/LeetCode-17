/*
  160_v1.cpp
  Intersection of Two Linked Lists

  My first submission got CE and my second submission didn't handle the case
  where headA or headB is NULL.
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *currA = headA, *currB = headB;
    if (currA == NULL || currB == NULL) return NULL;
    int lenA = 0, lenB = 0;
    while (currA->next != NULL) {
      lenA++;
      currA = currA->next;
    }
    while (currB->next != NULL) {
      lenB++;
      currB = currB->next;
    }
    if (currA != currB) return NULL;
    currA = headA, currB = headB;
    if (lenA > lenB)
      for (int i = 0; i < lenA - lenB; i++, currA = currA->next)
        ;
    else
      for (int i = 0; i < lenB - lenA; i++, currB = currB->next)
        ;
    while (currA != currB) {
      currA = currA->next;
      currB = currB->next;
    }
    return currA;
  }
};