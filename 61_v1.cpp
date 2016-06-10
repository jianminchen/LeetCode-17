/*
  61_v1.cpp
  Rotate List
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return NULL;
    int listLen = 0;
    ListNode* curr = head;
    while (curr != NULL) {
      listLen++;
      curr = curr->next;
    }
    k %= listLen;
    if (k == 0) return head;
    ListNode* prev = NULL;
    curr = head;
    int cnt = 0;
    while (cnt < listLen - k) {
      cnt++;
      prev = curr;
      curr = curr->next;
    }
    prev->next = NULL;
    ListNode* newHead = curr;
    while (curr->next != NULL) curr = curr->next;
    curr->next = head;
    return newHead;
  }
};