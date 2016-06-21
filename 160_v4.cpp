/*
  160_v4.cpp
  Intersection of Two Linked Lists

  My first submission got WA since I believe this algorithm doesn't need to
  handle the special case where headA or headB is NULL. Turns out I am right but
  in my first submission, I've written something like this:

  if (currA == NULL) currA = headB;
  if (currB == NULL) currB = headA;
  currA = currA->next;
  currB = currB->next;

  Well, then it is clearly incorrect, for a case like [1, 3] and [], currA and
  currB would both start from headA in the first iteration.
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
    while (currA != currB) {
      if (currA == NULL)
        currA = headB;
      else
        currA = currA->next;
      if (currB == NULL)
        currB = headA;
      else
        currB = currB->next;
    }
    return currA;
  }
};