/*
  24_v1.cpp
  Swap Nodes in Pairs

  My first submission got WA since I thought there would always be an even
  number of nodes in the linked list.
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
  ListNode* swapPairs(ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    ListNode* tmp = head->next->next;
    head->next->next = head;
    ListNode* tmp1 = head->next;
    head->next = swapPairs(tmp);
    return tmp1;
  }
};