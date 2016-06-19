/*
  148_v1.cpp
  Sort List
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
  ListNode* merge(ListNode* h1, ListNode* h2) {
    ListNode *dummyNode = new ListNode(0), *curr = dummyNode;
    ListNode *curr1 = h1, *curr2 = h2;
    while (curr1 && curr2) {
      if (curr1->val < curr2->val) {
        curr->next = curr1;
        curr1 = curr1->next;
      } else {
        curr->next = curr2;
        curr2 = curr2->next;
      }
      curr = curr->next;
    }
    while (curr1) {
      curr->next = curr1;
      curr = curr->next;
      curr1 = curr1->next;
    }
    while (curr2) {
      curr->next = curr2;
      curr = curr->next;
      curr2 = curr2->next;
    }
    curr->next = NULL;
    return dummyNode->next;
  }

  int countNodes(ListNode* head) {
    ListNode* curr = head;
    int ret = 0;
    while (curr) {
      curr = curr->next;
      ret++;
    }
    return ret;
  }

  void outputList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
      cout << curr->val << " ";
      curr = curr->next;
    }
    cout << endl;
  }

 public:
  ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    int numNodes = countNodes(head);
    ListNode* curr = head;
    for (int i = 0; i < numNodes / 2 - 1; i++, curr = curr->next)
      ;
    ListNode* h2 = curr->next;
    curr->next = NULL;
    ListNode* h1 = head;
    h1 = sortList(h1);
    h2 = sortList(h2);
    return merge(h1, h2);
  }
};