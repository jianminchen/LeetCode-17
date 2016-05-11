/*
  21_v1_im.cpp
  Merge Two Sorted Lists
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0), * head = dummy;
    while (l1 && l2) {
      if (l1->val < l2->val)
        dummy->next = l1, l1 = l1->next;
      else
        dummy->next = l2, l2 = l2->next;
      dummy = dummy->next;
    }
    dummy->next = l1 ? l1 : l2;
    return head->next;
  }
};