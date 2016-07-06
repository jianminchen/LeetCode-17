/*
  25_v1.cpp
  Reverse Nodes in k-Group
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
  int getListLen(ListNode* head) {
    int listLen = 0;
    ListNode* curr = head;
    while (curr) {
      curr = curr->next;
      listLen++;
    }
    return listLen;
  }

 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    int listLen = getListLen(head);
    ListNode *curr = head, *prev, *prevSegHead = NULL;
    ListNode* newHead = head;
    for (int i = 0; i < listLen / k; i++) {
      ListNode* prev2SegHead = prevSegHead;
      prevSegHead = curr;
      prev = NULL;
      for (int j = 0; j < k; j++) {
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
      }
      if (i == 0) newHead = prev;
      if (prev2SegHead != NULL) prev2SegHead->next = prev;
    }
    if (prevSegHead != NULL) prevSegHead->next = curr;
    return newHead;
  }
};