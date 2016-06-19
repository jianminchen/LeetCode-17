/*
  86_v1.cpp
  Partition List
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
  ListNode* partition(ListNode* head, int x) {
    ListNode *dummyNode1 = new ListNode(0), *dummyNode2 = new ListNode(0);
    ListNode *curr1 = dummyNode1, *curr2 = dummyNode2, *curr = head;
    while (curr != NULL) {
      if (curr->val < x) {
        curr1->next = curr;
        curr1 = curr;
      } else {
        curr2->next = curr;
        curr2 = curr;
      }
      curr = curr->next;
    }
    curr1->next = dummyNode2->next;
    curr2->next = NULL;
    return dummyNode1->next;
  }
};