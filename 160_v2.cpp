/*
  160_v2.cpp
  Intersection of Two Linked Lists

  I like this solution a lot. Suppose the length of linked list A is a + c and
  the length of linked list B is b + c. Then when two pointers meet currA should
  have visited a + c + b nodes and currB should have visited b + c + a nodes.
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
      currA = currA ? currA->next : headB;
      currB = currB ? currB->next : headA;
    }
    return currA;
  }
};