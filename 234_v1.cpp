/*
  234_v1.cpp
  Palindrome Linked List
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
  bool isPalindrome(ListNode *head) {
    if (head == NULL || head->next == NULL) return true;
    int listLen = 0;
    ListNode *curr = head;
    while (curr != NULL) {
      listLen++;
      curr = curr->next;
    }

    curr = head;
    ListNode *prev = NULL;
    for (int i = 0; i < listLen / 2; i++) {
      prev = curr;
      curr = curr->next;
    }
    prev = NULL;
    while (curr) {
      ListNode *tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    ListNode *curr1 = head, *curr2 = prev;
    while (curr1 && curr2) {
      if (curr1->val != curr2->val) return false;
      curr1 = curr1->next;
      curr2 = curr2->next;
    }
    return true;
  }
};