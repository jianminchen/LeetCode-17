/*
  369_v1.cpp
  Plus One Linked List
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
 private:
  ListNode* reverse(ListNode* head) {
    ListNode *prev = NULL, *curr = head;
    while (curr) {
      ListNode* tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    return prev;
  }

 public:
  ListNode* plusOne(ListNode* head) {
    ListNode* rHead = reverse(head);
    int carry = 1;
    ListNode *curr = rHead, *prev = NULL;
    while (curr && carry) {
      curr->val += carry;
      if (curr->val == 10) {
        carry = 1;
        curr->val = 0;
      } else
        carry = 0;
      prev = curr;
      curr = curr->next;
    }
    if (carry) {
      ListNode* newNode = new ListNode(carry);
      prev->next = newNode;
    }
    return reverse(rHead);
  }
};