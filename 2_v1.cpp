/*
  2_v1.cpp
  Add Two Numbers
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0), * head = dummy;
    int carry = 0;
    while (l1 || l2) {
      int val1 = l1 ? l1->val : 0;
      int val2 = l2 ? l2->val : 0;
      int val = (val1 + val2 + carry) % 10;
      carry = (val1 + val2 + carry) / 10;
      dummy->next = new ListNode(val);
      dummy = dummy->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    if (carry) dummy->next = new ListNode(carry);
    return head->next;
  }
};