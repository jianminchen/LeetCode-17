/*
  143_v1.cpp
  Reorder List
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
  void reorderList(ListNode* head) {
    int numNodes = 0;
    ListNode* curr = head;
    while (curr != NULL) {
      numNodes++;
      curr = curr->next;
    }
    curr = head;
    ListNode* dummy = new ListNode(0);
    dummy->next = curr;
    ListNode* prev = dummy;
    int cnt = 0;
    while (cnt < numNodes / 2) {
      cnt++;
      prev = curr;
      curr = curr->next;
    }
    prev->next = NULL;
    prev = NULL;
    while (curr != NULL) {
      ListNode* tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }

    /*
    curr = dummy -> next;
    while (curr != NULL) {
        cout << curr -> val << " ";
        curr = curr -> next;
    }
    cout << endl;
    curr = prev;
    while (curr != NULL) {
        cout << curr -> val << " ";
        curr = curr -> next;
    }
    cout << endl;
    */

    bool flag = true;
    ListNode *curr1 = dummy->next, *curr2 = prev;
    curr = dummy;
    while (curr1 || curr2) {
      if (flag) {
        if (curr1) {
          curr->next = curr1;
          curr1 = curr1->next;
          curr = curr->next;
        }
        flag = false;
      } else {
        if (curr2) {
          curr->next = curr2;
          curr2 = curr2->next;
          curr = curr->next;
        }
        flag = true;
      }
    }
  }
};